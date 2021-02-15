#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int massimo = 10;
int max_prod = 0;
int cont = 0;

struct catalogo{
    string nome;
    int num_ven;
};
catalogo prodotti[massimo];

void cerca_massimo(){
    int massimo = 0, posizione = 0;
    for (int i=0; i<max_prod; i++)
        if (prodotti[i].num_ven > massimo){
            massimo = prodotti[i].num_ven;
            posizione = i;
        }
    cout <<"Cliente: " <<prodotti[posizione].nome <<", con il numero di vendite: " <<prodotti[posizione].num_ven <<endl; 
}

void cerca_cliente(){
    int posizione;
    string cerca_nome;
    bool check = false;
    cout<<"Inserisci il nome da cercare: ";
    cin>>cerca_nome;
    for (int i=0; i<max_prod; i++)
        if (prodotti[i].nome == cerca_nome){
            posizione = i;
            check = true;
            break;
        }

    if (check)
        cout <<"Cliente: " <<prodotti[posizione].nome <<endl
        <<"Numero vendite: " <<prodotti[posizione].num_ven <<endl;
    else cout <<"Cliente non e presente." <<endl;
}

void ordinamento(){
    catalogo tmp;
    for (int i=0 ; i<max_prod-1; i++)
        for (int j=i+1; j<max_prod; j++)
            if (prodotti[i].nome > prodotti[j].nome){
                tmp = prodotti[i];
                prodotti[i] = prodotti[j];
                prodotti[j] = tmp;
            }
    for(int i=0; i<max_prod; i++) cout<<prodotti[i].nome <<"\t" <<prodotti[i].num_ven <<endl;
}

void stampa(){
    //Read file
    fstream list;
    list.open("file.txt", ios::in);
    
    //to check if the file is open
    if (list.is_open()){
        string read;
        //read every line on the file
        while (getline(list, read)){
            cout <<read <<endl;
        }
        list.close();
    } else cout <<"the file is closed so sorry";
}

void media_maggiori(){
    float media = 0;
    int cont = 0, vendite_plus;
    cout <<"Inserisci il valore: ";
    cin >>vendite_plus;
    for (int i=0; i<max_prod; i++)
        if (prodotti[i].num_ven > vendite_plus){
            cont++;
            media +=prodotti[i].num_ven;
        }
    media /=cont;
    cout <<"La media e uguale a: " <<media;
}

int main(){
    fstream list;

    list.open("file.txt", ios::in);
    
    while (!list.eof()){
        list >>prodotti[max_prod].nome >>prodotti[max_prod].num_ven;
        max_prod++;
    }
    int scelta;
    do{
        cout <<endl <<"Menu: " <<endl
            <<"  1 - cerca massimo" <<endl
            <<"  2 - cerca cliente" <<endl
            <<"  3 - ordinamento" <<endl
            <<"  4 - media dei maggiori" <<endl
            <<"  5 - stampa tutti" <<endl
            <<"Scelta: ";
        cin>>scelta;
        switch(scelta){
            case 0:
                cout<<"EXIT"<<endl;
            break;
            case 1:
                cerca_massimo();
            break;
            case 2:
                cerca_cliente();
            break;
            case 3:
                ordinamento();
            break;
            case 4:
                media_maggiori();
            break;
            case 5:
                stampa();
            break;
            default:
                cout<<"riprova"<<endl;
            break;
        }
    } while (scelta != 0);
    list.close();
}