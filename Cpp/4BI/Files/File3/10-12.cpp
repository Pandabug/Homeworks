#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAX = 100;
int s_now = 1;

struct studente{
    string cognome;
    string nome;
    string num_tel;
};
studente alunno[MAX];

void stampa(){
    //Read file
    fstream dati;

    dati.open("file.txt", ios::in);

    if (dati.is_open()){
        cout <<endl <<"---Lettura file---" <<endl <<endl;
        string read;
        while (getline(dati, read)){
            cout <<read <<endl;
        }
        dati.close();
    } else cout <<"The file does not exist." <<endl;
}

void sort(){
    studente tmp;
    for (int i=0 ; i<s_now-1; i++)
        for (int j=i+1; j<s_now; j++)
            if (alunno[i].nome > alunno[j].nome){
                tmp = alunno[i];
                alunno[i] = alunno[j];
                alunno[j] = tmp;
            }
    for(int i=0; i<s_now; i++) cout <<alunno[i].cognome <<"\t" <<alunno[i].nome <<"\t" <<alunno[i].num_tel <<endl;
}

int main(){
    //Create file
    fstream dati;

    dati.open("file.txt", ios::out);

    int scelta;
    do{
        cout <<"Menu: " <<endl
            <<" - 0 Per uscire" <<endl
            <<" - 1 Per inserire" <<endl
            <<" - 2 Per ordinare" <<endl
            <<" - 3 Per stampare file" <<endl
            <<"Scelta: ";
        cin >>scelta;
        cout <<endl;
        switch (scelta){
            case 0:
                cout <<"EXIT" <<endl;
            break;
            case 1:{
                cout <<"Inserisce cognome: ";
                cin >>alunno[s_now].cognome;
                cout <<"Inserisci nome: ";
                cin >>alunno[s_now].nome;
                cout <<"Inserisci il numero di telefono: ";
                cin >>alunno[s_now].num_tel; 
                cout <<endl;
                //Write to the file
                dati <<"Studente " <<s_now <<"\n";
                dati <<" - Cognome:  " <<alunno[s_now].cognome <<"\n";
                dati <<" - Nome:  " <<alunno[s_now].nome <<"\n";
                dati <<" - Numero di telefono: " <<alunno[s_now].num_tel <<"\n\n";
                
                s_now++;
            }
            break;
            case 2:
                sort();
            break;
            case 3:
                stampa();
            break;
            default:
                cout <<"Scelta sbagliata." <<endl;
            break;
        }
    } while (scelta != 0);
    //Close the file
    dati.close();
}