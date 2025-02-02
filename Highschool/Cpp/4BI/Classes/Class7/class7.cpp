#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const int maxConti = 10;
int currentConto = 0;

struct conto{
    string codiceConto;
    float saldo;
    string surname;
    string name;
};

class ContoCorrente{
    conto newConto[maxConti];

    public:
        void input(){
            cout<<"Inserisci Codice Conto: ";
            cin>>newConto[currentConto].codiceConto;
            cout<<"Inserisci Saldo: ";
            cin>>newConto[currentConto].saldo;
            cout<<"Inserisci Cognome: ";
            cin>>newConto[currentConto].surname;
            cout<<"Inserisci Nome: ";
            cin>>newConto[currentConto].name;

            currentConto++;
        }
        int searchConto(){
            int position = -1;
            string searchCodiceConto;

            cout<<"Inserisci il codice conto da cercare: ";
            cin>>searchCodiceConto;
            
            for (int i=0; i<currentConto; i++)
                if(newConto[i].codiceConto == searchCodiceConto){
                    position = i;
                    break;
                }

            return position;
        }
        void withdrawal(){
            int position = searchConto();

            if (position == -1) cout<<"Codice Conto non trovato." <<endl;
            else {
                float newSaldo;

                cout<<"Inserisci il ritiro: ";
                cin>>newSaldo;

                newConto[position].saldo = newSaldo;
            }
        }
        void payment(){
            int position = searchConto();

            if (position == -1) cout<<"Codice Conto non trovato." <<endl;
            else {
                float toPay;

                cout<<"Inserisci il pagamento: ";
                cin>>toPay;

                if (newConto[position].saldo > toPay) 
                    newConto[position].saldo -= toPay;
                else 
                    cout<<"Non hai abbastanza soldi." <<endl;
            }
        }
        void print(){
            int position = searchConto();

            if (position == -1) cout<<"Codice Conto non trovato." <<endl;
            else 
                cout<<"Codice Conto: " <<newConto[position].codiceConto <<endl
                    <<"Saldo: " <<newConto[position].saldo <<endl
                    <<"Cognome: " <<newConto[position].surname <<endl
                    <<"Nome: " <<newConto[position].name <<endl;
        }
        void shiftMoney(){
            int position1 = searchConto();

            if (position1 == -1) cout<<"Codice Conto non trovato." <<endl;
            else {
                int position2 = searchConto();
                    if (position2 == -1) cout<<"Codice Conto non trovato." <<endl;
                    else{
                        float shiftSaldo;

                        cout<<"Inserisci il saldo da versare: ";
                        cin>>shiftSaldo;
                        
                        if (newConto[position2].saldo > shiftSaldo){
                            newConto[position2].saldo -=shiftSaldo;
                            newConto[position1].saldo += shiftSaldo;
                        }
                        else cout<<"Non hai abbastanza soldi." <<endl;
                    }
            }
        }
        void MaxMin(){
            float max = 0;

            for (int i=0; i<currentConto; i++)
                if (newConto[i].saldo > max)
                    max = newConto[i].saldo;

            float min = 0;
            
            for (int i=0; i<currentConto; i++)
                if (newConto[i].saldo < min)
                    min = newConto[i].saldo;

            cout<<"Max: " <<max <<endl
                <<"Min: " <<min <<endl;
        }
        void file1(){
            ofstream file;
            file.open("file.txt");

            float media = 0;
            for (int i=0; i<currentConto; i++)
                media += newConto[i].saldo;
            media /= currentConto;

            for (int i=0; i<currentConto; i++)
                if (newConto[i].saldo > media)
                    file<<newConto[i].saldo<<"\n";
        }
        void sort(){
            conto tmp;
            
            for (int i=0; i<currentConto; i++)
                for (int j=0; j<currentConto; j++)
                    if (newConto[i].saldo < newConto[j].saldo){
                        tmp = newConto[i];
                        newConto[i] = newConto[j];
                        newConto[j] = tmp;
                    }

            for (int i=0; i<currentConto; i++)
                cout<<"Codice Conto: " <<newConto[i].codiceConto <<endl
                    <<"Saldo: " <<newConto[i].saldo <<endl
                    <<"Cognome: " <<newConto[i].surname <<endl
                    <<"Nome: " <<newConto[i].name <<endl <<endl;
        }
        void readFromFile(){
            fstream file;
            file.open("fileContiCorrenti.txt", ios::in);

            while(!file.eof()){
                file>>newConto[currentConto].codiceConto
                    >>newConto[currentConto].saldo
                    >>newConto[currentConto].surname
                    >>newConto[currentConto].name;
                currentConto++;
            }

            file.close();
        }
};

int main(){
    ContoCorrente newContoCorrente;

    int option;
    do{
        cout<<"Menu:" <<endl
            <<" - 0 EXIT" <<endl
            <<" - 1 Create new Conto Corrente" <<endl
            <<" - 2 Cambio saldo" <<endl
            <<" - 3 Paga" <<endl
            <<" - 4 Print" <<endl
            <<" - 5 Spostamento nell'altro" <<endl
            <<" - 6 Max Min" <<endl
            <<" - 7 Average > nel file" <<endl
            <<" - 8 Sort" <<endl
            <<" - 9 Read from file" <<endl
            <<"Option: ";
        cin>>option;
        cout<<endl;
        switch (option){
            case 0:
                cout<<"EXIT" <<endl;
            break;
            case 1:
                newContoCorrente.input();
            break;
            case 2:
                newContoCorrente.withdrawal();
            break;
            case 3:
                newContoCorrente.payment();
            break;
            case 4:
                newContoCorrente.print();
            break;
            case 5:
                newContoCorrente.shiftMoney();
            break;
            case 6:
                newContoCorrente.MaxMin();
            break;
            case 7:
                newContoCorrente.file1();
            break;
            case 8:
                newContoCorrente.sort();
            break;
            case 9:
                newContoCorrente.readFromFile();
            break;
            default:
                cout<<"Retry..." <<endl;
            break;
        }
    } while (option != 0);
}