#include <iostream>
#include <string>
#include <ctime>
using namespace std;

const int MaxMosse = 10;
int NumMossa = 0;


struct NumeroMosse{
    string data;
    string importo;
};

void delete_item(NumeroMosse mosse[MaxMosse]){
    for(int i=0; i<NumMossa; i++)
        mosse[i] = mosse[i+1];
    NumMossa--;
}
void register_process(NumeroMosse mosse[MaxMosse], char operation, float a){
    time_t now = time(0);
    string data = ctime(&now);

    if(NumMossa != MaxMosse-1){
        mosse[NumMossa].data = data;
        mosse[NumMossa].importo = operation + to_string(a);
        NumMossa++;
    } else {
        delete_item(mosse);
        mosse[NumMossa].data = data;
        mosse[NumMossa].importo = operation + to_string(a);
        NumMossa++;
    }
}

class ContoCorrente{
    string correntista, NumeroConto;
    float saldo, rate;

    NumeroMosse mosse[MaxMosse];
    
    public:
        ContoCorrente(float a, float rateIn){
            saldo = a;
            rate = rateIn;
        }
        void prelievo(float a){
            time_t now = time(0);
            string data = ctime(&now);

            if (saldo > a){
                saldo -= a;
                cout <<endl <<"Il saldo attuale e di euro: " <<saldo <<endl;
            } else {
                cout <<endl<<"Non e possibile effettuare il prelievo di una cifra." <<endl
                     <<"superiore al saldo attuale che ammonta a euro: " <<saldo <<endl;
            }
        }
        void versamento(float a){
            time_t now = time(0);
            string data = ctime(&now);

            if(a > 0){
                saldo += a;
                cout<<"Saldo attuale: " <<saldo <<endl;
            } else cout<<"Importo non valido." <<endl;

            register_process(mosse, '+', a);
        }
        void stampa(){
            cout <<endl <<"Numero conto: " <<NumeroConto <<endl
                 <<"Correntista: " <<correntista <<endl
                 <<"Saldo: " <<saldo <<endl
                 <<"Interesse: " <<rate <<endl;
        }
        void crea(){
            cout <<endl <<"Inserire numero conto: ";
            cin >>NumeroConto;
            cout <<"Inserire il cognome del corentista: ";
            cin >>correntista;
        }
        void modify_rate(float interest_rate){
            interest_rate = interest_rate;
        }
        void TassaInteresse(){}
        void TotMosse(){
            for (int i=0; i<NumMossa; i++)
                cout<<"Data: " <<mosse[i].data <<"Operazione: " <<mosse[i].importo <<endl <<endl;
        }
};

int main(){
    ContoCorrente conto(0, 0);
    conto.crea();
    
    float a;
    int option;
    do{
        cout <<endl <<"Menu:" <<endl
            <<" 0 - EXIT." <<endl
            <<" 1 - Prelievo." <<endl 
            <<" 2 - Versameto." <<endl
            <<" 3 - Stampa informazioni relative al conto." <<endl
            <<" 4 - Modifica il tasso di interesse." <<endl
            <<" 5 - Applica il tasso di interesse attuale al saldo." <<endl
            <<" 6 - Stampa l'elenco delle operazioni effettuate." <<endl
            <<"Option: ";
        cin >>option;
        switch (option){
            case 0:
                cout <<"EXIT" <<endl;
            break;
            case 1:
                cout <<"Inserire la cifra prelevare: ";
                cin >>a;
                conto.prelievo(a);
            break;
            case 2:
                cout <<"Inserire la cifra da versare: ";
                cin >>a;
                conto.versamento(a);
            break;
            case 3:
                conto.stampa();
            break;
            case 4:
                float interest_rate;
                cout<<"Inserire il nuovo tasso di interesse: ";
                cin>>interest_rate;
                conto.modify_rate(interest_rate);
            break;
            case 5:
                conto.TassaInteresse();
            break;
            case 6:
                conto.TotMosse();
            break;
            default:
                cout <<"Retry..." <<endl;
            break;
        }
    } while (option != 0);
}