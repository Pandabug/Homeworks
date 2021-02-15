#include<iostream>
using namespace std;

int x[10];
void input(){
cout<<"Inserisci 10 valori"<<endl;
for(int i=0;i<10;i++){
    cout<<"Posizione "<<i+1<<" valore: ";
    cin>>x[i];
}
}
void order(){
int tmp,y;
for(int i=0;i<9;i++){
    for(int y=i+1;y<10;y++){
        if(x[y]<x[i]){
            tmp=x[i];
            x[i]=x[y];
            x[y]=tmp;
        }
    }
}
cout<<endl;
cout<<"VALORI ORDINATI:"<<endl;
    for(int z=0;z<10;z++){
        cout<<"Posizione "<<z+1<<" valore: "<<x[z]<<endl;
    }
}
int main(){
input();
order();
}
