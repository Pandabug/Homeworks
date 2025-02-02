#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

struct rubrica{
    string surname;
    string name;
    int phoneNumbe;
    string type;
    struct rubrica *next;
};

class tail{
    rubrica *head;
    rubrica *end;
    vector<rubrica*> myArray;

    public:
        tail(){
            head = NULL;
            end = NULL;
        }
        // Input
        void push(){
            rubrica *p;
            int typeTo;

            p = new(rubrica);
            cout<<"Input surname: ";
            cin>>p->surname;
            cout<<"Input name: ";
            cin>>p->name;
            cout<<"Input phone number: ";
            cin>>p->phoneNumbe;
            cout<<"Input type (0 - work, 1 - private): ";
            cin>>typeTo;
            cout<<endl;
            
            if (typeTo == 0)
                p->type = "work";
            else 
                p->type = "private";
            
            p->next = NULL;

            p -> next = head;
            head = p;
        }
        // Input from file
        void pushFile(){
            rubrica *p;
            int typeTo;
            fstream MyFile;

            MyFile.open("file.txt", ios::in);

            while(!MyFile.eof()){
                p = new(rubrica);
                MyFile  >>p->surname 
                        >>p->name 
                        >>p->phoneNumbe 
                        >>p->type;
                p->next = NULL;

                if (head == NULL) 
                    head = end = p;
                else{
                    end->next = p;
                    end = p;
                }
            }
            MyFile.close();
                
        }
        // Remove
        void pop(){
            rubrica *p = NULL;
            rubrica *pp;
            string get_surname_to_delete;

            cout<<"Input surname to delete form the list: ";
            cin>>get_surname_to_delete;

            for(rubrica* i=head; i!=NULL; i=i->next){
                if (i->surname == get_surname_to_delete){
                    p = i;
                    break;
                }
                pp = i;
            }

            if(p == NULL) cout<<"Code doesn't exist." <<endl;
            else {
                if(head == NULL) cout<<"The list is empty." <<endl;
                else if(p != head) pp->next = p->next;
                else head = p->next;
                
                cout<<"Surname: " <<p->surname <<", name: " <<p->name <<", phone number: " <<p->phoneNumbe <<", type: " <<p->type <<endl;
                
                if (p == NULL)
                    end = NULL;
                
                delete p;
            }
        }
        // Print
        void print(){
            rubrica *p;
            
            if (head == NULL) cout<<"The list is empty." <<endl;
            else{
                cout<<"RUBRICA TELEFONICA:" <<endl;
                for (p=head; p!=NULL; p=p->next) 
                    cout<<"Surname: " <<p->surname <<", name: " <<p->name <<", phone number: " <<p->phoneNumbe <<", type: " <<p->type <<endl;
                cout<<endl;
            }
        }
        // Add To A File
        void addToFile(){
            rubrica *p;
            fstream MyFile;

            MyFile.open("Rubrica.txt", ios::out);
            if (MyFile.is_open()){
                for (p=head; p!=NULL; p=p->next) 
                    if (p->type == "private")
                        MyFile<<"Surname: " <<p->surname <<", name: " <<p->name <<", phone number: " <<p->phoneNumbe <<", type: " <<p->type <<endl;
                MyFile.close();
            }
        }
        // Input in Array
        void addToArray(){
            for (rubrica *i=head; i!=NULL; i=i->next)
                if (i->type == "work"){
                    myArray.push_back(i);
                }
        }
        // Sort
        void sortArray(){
            rubrica *tmp;

            for (int i=0; i<myArray.size(); i++)
                for (int j=i+1; j<myArray.size(); j++)
                    if (myArray[i]->surname > myArray[j]->surname){
                        tmp = myArray[i];
                        myArray[i] = myArray[j];
                        myArray[j] = tmp;
                    }
            if (myArray.size() == 0) cout<<"Array is empty." <<endl;
            else
                for (int i=0; i<myArray.size(); i++)
                    cout<<"Surname: " <<myArray[i]->surname <<", name: " <<myArray[i]->name <<", phone number: " <<myArray[i]->phoneNumbe <<", type: " <<myArray[i]->type <<endl;
                cout<<endl;
        }
        // Input Afther x position
        void addAtPosition(){
            int inputPosition, position = 0;
            rubrica *p, *pp = NULL;

            cout<<"Input position: ";
            cin>>inputPosition;
            push();
            for(rubrica *i=head; i!=NULL; i=i->next){
                if (position == inputPosition){
                    pp = i;
                    break;
                }
                position++;
            }
            if (head == NULL)
                if (pp == NULL) cout<<"Incorrect position." <<endl;
                else{
                    p->next = pp->next;
                    pp->next = p;
                }
            else cout<<"The list is empty."<<endl;
        }
};

int main(){
    tail rubricaTelefonica;
    int option;
    
    rubricaTelefonica.pushFile();

    do {
        cout<<"Menu:" <<endl
            <<" - 0 EXIT" <<endl
            <<" - 1 Input" <<endl
            <<" - 2 Delete" <<endl
            <<" - 3 Print" <<endl
            <<" - 4 Add to file" <<endl
            <<" - 5 Add to array" <<endl
            <<" - 6 Sort array" <<endl
            <<" - 7 Input afther x position" <<endl
            <<"Option: ";
        cin>>option;
        cout<<endl;
        switch (option){
            case 0:
                cout<<"EXIT" <<endl;
            break;
            case 1:
                rubricaTelefonica.push();
            break;
            case 2:
                rubricaTelefonica.pop();
            break;
            case 3:
                rubricaTelefonica.print();
            break;
            case 4:
                rubricaTelefonica.addToFile();
            break;
            case 5:
                rubricaTelefonica.addToArray();
            break;
            case 6:
                rubricaTelefonica.sortArray();
            break;
            case 7:
                rubricaTelefonica.addAtPosition();
            break;
            default:
                cout<<"Retry..." <<endl;
            break;
        }
    } while (option != 0);
}