#include <iostream>
using namespace std;

int const MAX=10;
int n;
float V[MAX];

void input();
void add();
void elimina();
void print();

void input(){
        for(int i=0;i<MAX;i++){
            cout<<i<<" Inserisci il numero: ";
            cin>>n;
            V[i]=n;
    }
}

void add(){
    int  ad;
        cout<<"Inserire la posizione del valore da eliminare: ";
        cin>>ad;
        if(ad<n && ad>=0){
            for(int i=0;i<n;i++){
                if(ad == i){
                    for(int p=ad;p<MAX;p++){
                        V[p+1]=V[p];
                    }
                }
            }
            cout<<"Valore eliminato correttamente." <<endl;
            n+=1;
        }
        else {
            cout<<"Non e' possibile cancellare il valore nella posizione indicata, riprova.";
        }
}

void elimina(){
    int pos;
        cout<<"Inserire la posizione del valore da eliminare: ";
        cin>>pos;
        if(pos<n && pos>=0){
            for(int i=0;i<n;i++){
                if(pos == i){
                    for(int p=pos;p<MAX;p--){
                        V[p]=V[p+1];
                    }
                }
            }
            cout<<"Valore eliminato correttamente." <<endl;
            n-=1;
        }
        else {
            cout<<"Non e' possibile cancellare il valore nella posizione indicata, riprova.";
        }
}

void print(){
    for(int i=0;i<MAX;i++){
        cout<<"Posizione "<<i<<" numero: "<<V[i]<<endl;
    }
}

int main(){
    input();
    char s;
        while(s!='q'){
            cout<<"Scegli tra:"<<endl;
            cout<<"1 - Aggiungere un valore"<<endl;
            cout<<"2 - Eliminare un valore"<<endl;
            cout<<"3 - Stampa tutti i valori"<<endl;
            cout<<"q - Per uscire dal programma"<<endl;
            cin>>s;
        switch(s){
        case'1':
            add();
            break;
        case'2':
            elimina();
            break;
        case'3':
            print();
            break;
        default:
            cout<<"L'opzione non e presente. Riprova."<<endl;
            break;

        }
    }
}
