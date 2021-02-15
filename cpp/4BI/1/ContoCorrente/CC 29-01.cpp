#include <iostream>
#include <string>
#include <ctime>
using namespace std;

const int MaxMosse = 10;
int NumMossa = 0;

struct ContaMosse{
    string data;
    string importo;
};

void delete_item(ContaMosse mosse[MaxMosse]){
    for (int i=0; i<NumMossa; i++)
        mosse[i] = mosse[i+1];
    NumMossa--;
}
void register_process(ContaMosse mosse[MaxMosse], char operation, float a){
    time_t now = time(0);
    string data = ctime(&now);

    if (NumMossa != MaxMosse-1){
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
    
    ContaMosse mosse[MaxMosse];

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
                register_process(mosse, '-', a);
            } else {
                cout <<endl<<"Non e possibile effettuare il prelievo di una cifra." <<endl
                     <<"superiore al saldo attuale che ammonta a euro: " <<saldo <<endl;
            }
        }
        void versamento(float a){
            time_t now = time(0);
            string data = ctime(&now);
            
            if (saldo > 0){
                saldo += a;
                cout<<"Saldo attuale: " <<saldo <<endl;
            } else cout<<"Importo non valido." <<endl;
            register_process(mosse, '+', a);
        }
        void stampa(){
            cout <<endl <<"Numero conto: " <<NumeroConto <<endl
                 <<"Correntista: " <<correntista <<endl
                 <<"Saldo: " <<saldo <<endl
                 <<"Tasso di interesse: " <<rate <<endl
                 <<"Lista movimenti" <<endl;
                for(int i=0; i<NumMossa; i++)
                    cout <<"Data " <<mosse[i].data <<" di " <<mosse[i].importo <<endl;
        }
        void crea(){
            cout <<"Inserire cognome intestatario: ";
            cin >>correntista;
            cout <<"Inserire numero conto: ";
            cin >>NumeroConto;
            cout <<"Inserire il tasso di interesse: ";
            cin >>rate;
        }
        void TassaInteresse(float rate){
            saldo += saldo / 100 * rate;
            cout<<"Saldo attuale: " <<saldo <<endl;
        }
        string TotMosse(){
            return NumeroConto;
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
                conto.TassaInteresse(interest_rate);
            break;
            case 5:

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