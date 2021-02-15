#include <iostream>
#include <string>
using namespace std;

class ContoCorrente{
    string correntista;
    string NumeroConto;
    float saldo;
    
    public:
        ContoCorrente(float a){
            saldo = a;
        }
        void prelievo(float a){
            if (saldo > a){
                saldo = saldo - a;
                cout <<endl <<"Il saldo attuale e di euro: " <<saldo <<endl;
            } else {
                cout <<endl<<"Non e possibile effettuare il prelievo di una cifra." <<endl
                     <<"superiore al saldo attuale che ammonta a euro: " <<saldo <<endl;
            }
        }
        void versamento(float a){
            saldo = saldo + a;
            cout <<"Il saldo attuale e di euro: " <<saldo <<endl;
        }
        void stampa(){
            cout <<endl <<"Numero conto: " <<NumeroConto <<endl
                 <<"Correntista: " <<correntista <<endl
                 <<"Saldo: " <<saldo <<endl;
        }
        void crea(){
            cout <<endl <<"Inserire numero conto: ";
            cin >>NumeroConto;
            cout <<"Inserire il cognome del corentista: ";
            cin >>correntista;
        }
};

int main(){
    ContoCorrente conto(0);
    conto.crea();
    
    float a;
    int option;
    do{
        cout <<endl <<"Menu:" <<endl
             <<" 0 - Exit" <<endl
             <<" 1 - Prelievo" <<endl
             <<" 2 - Versamento" <<endl
             <<" 3 - Stampa dati del conto" <<endl
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
            default:
                cout <<"Retry..." <<endl;
            break;
        }
    } while (option != 0);
}