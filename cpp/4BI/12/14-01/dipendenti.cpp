#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const int MAX = 10;
int n_people = 0;

struct dipendenti{
    string cognome;
    string nome;
    int age;
    float stipendio;
};
dipendenti persona[MAX];

void transfer_to_another_file();
void print_employees_by_seniority(int seniority);

int main(){
    ifstream dati;

    dati.open("stipendio.txt");

    cout <<endl <<"---Lettura file---" <<endl <<endl;
    while (!dati.eof()){
        dati >>persona[n_people].cognome >>persona[n_people].nome >>persona[n_people].age >>persona[n_people].stipendio;
        n_people++;
    }
    cout <<endl;
    
    int scelta;
    do{
        cout <<"Menu:" <<endl
            << " -0 EXIT" <<endl
            <<" - 1 To transfer dates with salary < 1500" <<endl
            <<" - 2 To search someono with age magg "<<endl
            <<"Scelta: ";
        cin >>scelta;
        cout <<endl;
        switch (scelta){
            case 0:
                cout <<"EXIT" <<endl;
            break;
            case 1:
                transfer_to_another_file();
            break;
            case 2:{
                    int seniority;
                    cout<<"Inserire l'anzianita' di riferimento: ";
                    cin>>seniority;
                    print_employees_by_seniority(seniority);
                }
            break;
            default:
                cout <<"Try again" <<endl;
            break;
        }
    } while (scelta != 0);
    dati.close();
}


void transfer_to_another_file(){
    ofstream output;

    output.open("stipendio1.txt");

    for (int i=0; i<n_people; i++){
        if (persona[i].stipendio > 1500){
            output <<persona[i].cognome <<" " <<persona[i].nome <<" " <<persona[i].age <<" " <<persona[i].stipendio <<endl;
        }
    }
}

void print_employees_by_seniority(int seniority){
    int seniority_cont = 0;

    for(int i=0; i<n_people; i++){
        if(persona[i].age == seniority){
            cout<<persona[i].nome <<" " <<persona[i].cognome <<endl;
            seniority_cont++;
        }
    }

    if(seniority_cont == 0) cout<<"Nessun dipendente trovato con questa anzianita'." <<endl;
}