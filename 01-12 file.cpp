#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAX = 100;
int max_s = 0;

struct studente{
    string cognome;
    int eta;
};
studente alunno[MAX];

void sort(){
    studente tmp;
    for (int i=0 ; i<max_s-1; i++)
        for (int j=i+1; j<max_s; j++)
            if (alunno[i].eta > alunno[j].eta){
                tmp = alunno[i];
                alunno[i] = alunno[j];
                alunno[j] = tmp;
            }
    for(int i=0; i<max_s; i++) cout <<alunno[i].cognome <<"\t" <<alunno[i].eta <<endl;
}

int main(){
    //Create file
    fstream dati;

    dati.open("file.txt", ios::in);
    
    while (!dati.eof()){
        dati >>alunno[max_s].cognome >>alunno[max_s].eta;
        max_s++;
    }
    int scelta;
    do{
        cout <<"Menu: " <<endl
            <<" - 0 Per uscire" <<endl
            <<" - 1 Per vedere i maggiorenni" <<endl
            <<" - 2 Per ordinare" <<endl
            <<"Scelta: ";
        cin >>scelta;
        cout <<endl;
        switch (scelta){
            case 0:
                cout <<"EXIT" <<endl;
            break;
            case 1:{
                cout <<"I studenti maggiorenni sono: " <<endl;
                for (int i=0; i<max_s; i++){
                    if (alunno[i].eta >= 18) cout <<"Cognome: " <<alunno[i].cognome <<endl <<"Eta: " <<alunno[i].eta <<endl <<endl;
                }
            }
            break;
            case 2:
                sort();
            break;
            default:
                cout <<"Scelta sbagliata." <<endl;
            break;
        }
    } while (scelta != 0);
    //Close the file
    dati.close();
}