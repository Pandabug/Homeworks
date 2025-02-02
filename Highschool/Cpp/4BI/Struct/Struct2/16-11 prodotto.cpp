#include <iostream>
#include <string>
using namespace std;

const int max_size = 10;
int t_max = 0;

struct prodotto{
    string cod;
    string des;
    float prezzo;
};
struct prodotto prod[max_size];


void caricamento(){
    cout<<"inserisci il numero massimo dei prodotti: ";
    cin>>t_max;
    cout<<endl;
    for (int i=0; i<t_max; i++){
        cout<<"Inserisci il codice del prodotto: ";
        cin>>prod[i].cod;
        cout<<"Inserisci la descrizione del prodotto: ";
        cin>>prod[i].des;
        cout<<"Inserisci il prezzo del prodotto: ";
        cin>>prod[i].prezzo;
        cout<<endl;
    }
}

void carica_new(){
    cout<<"Inserisci il codice del prodotto: ";
        cin>>prod[t_max].cod;
        cout<<"Inserisci la descrizione del prodotto: ";
        cin>>prod[t_max].des;
        cout<<"Inserisci il prezzo del prodotto: ";
        cin>>prod[t_max].prezzo;
        t_max++;
        cout<<endl;
}

void ordinamento(){
    prodotto temp;
    for (int i=0 ; i<t_max-1; i++){
        for (int j=i+1; j<t_max; j++){
            if (prod[i].cod < prod[j].cod){
                temp = prod[i];
                prod[i] = prod[j];
                prod[j] = temp;
            }
        }
    }
}

void stampa(){
    cout<<"I prodotti inseriti sono: "<<endl;
    for (int i=0; i<t_max; i++){
        cout<<prod[i].cod<<"\t"<<prod[i].des<<"\t"<<prod[i].prezzo<<"$"<<endl;
    }
    cout<<endl;
}

void kill_prod(){
    bool check = false;
    int pos;
    string surname;
    cout<<"Inserisci il nome prodotto da eliminare: ";
    cin>>surname;
    for (int i=0; i<t_max; i++){
        if (prod[i].des == surname){
            check=true;
            pos=i;
        }
    }
    if (check){
        for (int i=pos; i<t_max; i++){
            prod[i]=prod[i+1];
        }
        cout<<"Prodotto e stato eliminato dalla lista correttamente."<<endl<<endl;
        t_max--;
    } else{
        cout<<"Nome prodotto non e presente nella lista."<<endl<<endl;
    }
}
/*void kill_prod(){
    bool check = false;
    int pos;
    string surname;
    cout<<"Inserisci il nome prodotto da eliminare: ";
    cin>>surname;
    for (int i=0; i<t_max; i++){
        if (prod[i].des == surname){
            check=true;
            prod[i]=prod[i+1];
            t_max--;
            break;
        }
    }
    if (check){
        cout<<"Prodotto e stato eliminato dalla lista correttamente."<<endl<<endl;
    } else{
        cout<<"Nome prodotto non e presente nella lista."<<endl<<endl;
    }
}*/
void menu(){
    int choice;
    caricamento();
    do{
    cout<<"In questo momento ci sono: "<<t_max<<" prodotti caricati.\nMenu scelte:\n  -0 Per uscire dal programma\n  -1 Per caricare un nuovo prodotto\n  -2 Per ordinare i prodotti\n  -3 Per stampare i prodotti\n  -4 Per eliminare il prodotto dalla lista\nScelta: ";
    cin>>choice;
    cout<<endl;
        switch (choice){
            case 0:
                cout<<"Hai deciso di uscire dal programma"<<endl;
            break;
            case 1:
                carica_new();
            break;
            case 2:
                ordinamento();
            break;
            case 3:
                stampa();
            break;
            case 4:
                kill_prod();
            break;
            default:
                cout<<"Opzione che lei ha inserito non e valida\nRiprova"<<endl<<endl;
            break;
        }
    } while(choice != 0);
    return ;
}

int main(){
    menu();
}