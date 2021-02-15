#include <iostream>
#include <string>
#include <ctime>
using namespace std;

int lim_1 = 0;
int pag = 200;
const int max_char = 24;
const int lim = 10;

//crea struttura
struct associazione{
    string cognome;
    string data_acconto;
    string data_saldo;
    float acconto;
};
struct associazione ass[lim];

//inserimento
void input(int lim_1){
    for(int i=0; i<lim_1; i++){
        cout<<"Inserisci il cognome dell'ospite "<<i+1<<": ";
        cin>>ass[i].cognome;
        ass[i].data_acconto="";
        ass[i].data_saldo="";
        ass[i].acconto=0;
    }
}

//aggiungi un nuovo utente
void new_input(){
    cout<<"Inserisci il cognome del nuovo ospite: ";
    cin>>ass[lim_1].cognome;
    ass[lim_1].data_acconto="";
    ass[lim_1].data_saldo="";
    ass[lim_1].acconto=0;
    lim_1++;
    cout<<endl;
}

//stampa utenti che devono ancora completare il pagamento
void to_pay(){
    cout<<"Utenti che devono ancora completare il pagamento: \n";
    for (int i=0; i<lim_1; i++){
        if (ass[i].acconto<pag){
            cout<<ass[i].cognome<<"\t"<<ass[i].acconto<<"$"<<endl;
        }
    }
    cout<<endl;
}

//aggiorna pagamenti
void data_pagamento(){
    //data
    char data[6];
    time_t current;
    tm * current_tm;
    time(&current);
    current_tm = localtime(&current);
    strftime(data, 50, "%d%m%y", current_tm);

    //pagamento
    char cognome[max_char];
    float soldi;
    cout<<"Nome utente che sta svolgendo il pagamento: ";
    cin>>cognome;
    cout<<"Pagamento totale di: ";
    cin>>soldi;
    for (int i=0; i<lim_1; i++){
        if (cognome == ass[i].cognome){
            if (soldi == pag){
                ass[i].acconto = pag;
                ass[i].data_saldo = data;
            }
            else if (soldi == 0){
                ass[i].acconto = soldi;
                ass[i].data_acconto = data;
            }
            else {
                ass[i].acconto += soldi;
                ass[i].data_acconto = data;
            }
        }
    }
}

//elimina utente
void kill_utente(){
    bool check=false;
    int cont;
    string surname;
    cout<<"Inserisci il cognome: ";
    cin>>surname;
    for (int i=0; i<lim_1; i++){
        if (ass[i].cognome==surname){
            check=true;
            cont=i;
        }
    }
    if (check){
        for (int i=cont; i<lim_1; i++){
            ass[i]=ass[i+1];
        }
        cout<<"Utente e stato eliminato correttamente"<<endl<<endl;
        lim_1--;
    }
    else{
        cout<<"Utente innesistente"<<endl<<endl;
    }
}

//menu scelte
void menu(){
    cout<<"Avvio programma..."<<endl<<endl;
    int var;
    cout<<"Inserire il numero massimo dei utenti: ";
    cin>>lim_1;
    input(lim_1);
    do{
        cout<<"General menu:\n  -0 Per uscire dal programma\n  -1 Per inserire un nuovo utente\n  -2 Per stampare utenti che devono ancora pagare\n  -3 Per pagare\n  -4 Per eliminare utente\n  La tua scelta: ";
        cin>>var;
        cout<<endl;
        switch (var){
            case 0:
                cout<<"Hai deciso di uscire dal programma\n";
            break;
            case 1:
                new_input();
            break;
            case 2:
                to_pay();
            break;
            case 3:
                data_pagamento();
            break;
            case 4:
                kill_utente();
            break;
        }
    } while(var != 0);
    return ;
}

int main(){;
    menu();
}