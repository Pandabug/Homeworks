#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const int MaxSize = 100;
const int Subject = 5;
const int Voto = 1000;
const string subjects[5] = {"Italiano", "Storia", "Inglese", "Informatica", "Ginnastica"};
int currentStudent = 0;
int cont = 0;

struct studentStruct{
    string surname;
    string name;
    string classroom;
    string address;
    float vote[Subject][Voto];
};

class students{
    studentStruct student[MaxSize];
    
    public:
        void checkExistence(){
            bool check = false;
            string checkSurname;

            cout<<"Input a surname: ";
            cin>>checkSurname;
            for(int i=0; i<currentStudent; i++)
                if (student[i].surname == checkSurname){
                    check = true;
                }
            if (!check) data(checkSurname);
            else cout<<"This surname is alredy exist please retry." <<endl;
        }
        void data(string checkSurname){
            student[currentStudent].surname = checkSurname;
            cout<<"Input a name: ";
            cin>>student[currentStudent].name;
            cout<<"Input a class: ";
            cin>>student[currentStudent].classroom;
            cout<<"Input a address: ";
            cin>>student[currentStudent].address;
            currentStudent++;
        }
        //search surname to input vote and to change data
        float searchStudent(){
            int position = -1;
            string searchSurname;

            cout<<"Input a surname of the student: ";
            cin>>searchSurname;
            
            for (int i=0; i<currentStudent; i++){
                if (student[i].surname == searchSurname){
                    position = i;
                    break;
                }
            }
            return position;
        }
        void evaluate(){
            int position = searchStudent();
            if(position == -1) cout<<"Surname didn't found." <<endl;
            else{
                float voto;
                int switchSubject;

                cout<<"Input a vote: ";
                cin>>voto;
                cout<<"Input a subject:\n 0 - Italiano\n 1 - Storia\n 2 - Inglese\n 3 - Informatica\n 4 - Ginnastica:\nOption: ";
                cin>>switchSubject;

                if (voto > 0 && voto < 11){
                    switch (switchSubject){
                        case 0:
                            student[position].vote[0][cont++] = voto;   //ita
                        break;
                        case 1:
                            student[position].vote[1][cont++] = voto;   //sto
                        break;
                        case 2:
                            student[position].vote[2][cont++] = voto;   //ing
                        break;
                        case 3:
                            student[position].vote[3][cont++] = voto;   //info
                        break;
                        case 4:
                            student[position].vote[4][cont++] = voto;   //gym
                        break;
                        default:
                            cout<<"Incorrect subject." <<endl;
                        break;
                    }
                } else cout<<"The vote you deduced is not valid. Retry."<<endl;
            }
        }
        void readfile(){
            int position = searchStudent();
            if(position == -1) cout<<"Surname didn't found." <<endl;
            else{
                //File
                fstream filesub;
                //open a file
                filesub.open("filevoti.txt", ios::in);

                float voto;
                int switchSubject;

                if (filesub.is_open()){
                    while (!filesub.eof()){
                        filesub >>switchSubject >>voto;
                            if (voto > 0 && voto < 11){
                                student[position].vote[switchSubject][cont++] = voto;
                            } else cout<<"One of the votes is incorrect." <<endl;
                    }
                } else cout<<"File did't find." <<endl;

                filesub.close();
            }
        }
        void printData(){
            order();
            for (int i=0; i<currentStudent; i++){
                cout<<"Surname: " <<student[i].surname <<endl 
                    <<"Name: " <<student[i].name <<endl 
                    <<"Class: " <<student[i].classroom <<endl 
                    <<"Address: " <<student[i].address <<endl <<endl;
                    // <<"Average Tot: " <<media <<endl <<endl;
            }
        }
        void printSingleData(){
            order();
            int contAllVotes = 0;
            for (int i=0; i<currentStudent; i++){
                cout<<"Surname: " <<student[i].surname <<endl 
                    <<"Name: " <<student[i].name <<endl 
                    <<"Class: " <<student[i].classroom <<endl 
                    <<"Address: " <<student[i].address <<endl
                    <<"Average: " <<endl;

                for (int j=0; j<Subject; j++){
                    float average = 0;
                    int contAverage = 0;
                    for (int k=0; k<cont; k++)
                        if (student[i].vote[j][k] != 0){
                            average += student[i].vote[j][k];
                            contAverage++;
                        }

                    cout<<" -"<<subjects[j] <<": " <<average / contAverage <<endl;
                }
                cout<<endl;
            }
        }
        void changeData(){
            int position = searchStudent();
            int whatChange;
            string newAddress, newClassroom;
            if(position == -1) cout<<"Surname didn't found." <<endl;
            else{
                cout<<"Input 0 to change class or 1 to change address: ";
                cin>>whatChange;
                switch (whatChange){
                    case 0:
                        cout<<"Input class: ";
                        cin>>newClassroom;
                        student[position].classroom = newClassroom;
                    break;
                    case 1:
                        cout<<"Input address: ";
                        cin>>newAddress;
                        student[position].address = newAddress;
                    break;
                    default:
                        cout<<"Somthing going wrong. Please retry.." <<endl;
                    break;
                }
            }
        }
        void order(){
            studentStruct tmp;
            for (int i=0 ; i<currentStudent-1; i++)
                for (int j=i+1; j<currentStudent; j++)
                    if (student[i].surname > student[j].surname){
                        tmp = student[i];
                        student[i] = student[j];
                        student[j] = tmp;
                    }
        }
};

int main(){
    students addstudent;

    int option;
    do{
        cout<<endl <<"Menu:" <<endl
            <<" - 0 EXIT." <<endl
            <<" - 1 Add student." <<endl
            <<" - 2 Give an estimate." <<endl
            <<" - 3 Read all stimate from the file." <<endl
            <<" - 4 Change data(Class or Address)." <<endl
            <<" - 5 Print an ordered list of all students." <<endl
            <<" - 6 Print an ordered list of all students with single subject vote." <<endl
            <<"Option: ";
        cin>>option;
        cout<<endl;
        switch(option){
            case 0:
                cout<<"EXIT" <<endl;
            break;
            case 1:
                addstudent.checkExistence();
            break;
            case 2:
                addstudent.evaluate();
            break;
            case 3:
                addstudent.readfile();
            break;
            case 4:
                addstudent.changeData();
            break;
            case 5:
                addstudent.printData();
            break;
            case 6:
                addstudent.printSingleData();
            break;
            default:
                cout<<"Retry..." <<endl;
            break;
        }
    } while (option != 0);
    return 0;
}
