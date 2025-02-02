#include <iostream>
#include <string>
using namespace std;

int main(){
 float T_Day,T_Week=0;
 string Giorno;
 const int Dim_Collonne=7;
 const int Dim_Righe=3;
 int T[Dim_Righe][Dim_Collonne];
 
 for(int i=0; i<Dim_Collonne; i++){
    float x=0;
    switch(i){
    case 0:
        Giorno = "Lunedi";
        break;
    case 1:
        Giorno = "Martedi";
        break;
    case 2:
        Giorno = "Mercoledi";
        break;
    case 3:
        Giorno = "Giovedi";
        break;
    case 4:
        Giorno = "Venerdi";
        break;
    case 5:
        Giorno = "Sabato";
        break;
    case 6:
        Giorno = "Domenica";
        break;
        }
    for(int j=0; j<Dim_Righe; j++){
        cout<<"Inserire temperatura "<<j+1<<" del giorno "<<Giorno<<": ";
        cin>>T[j][i];
    }
    for(int j=0; j<Dim_Righe; j++){
        x += T[j][i];
    }
    T_Week += x;
    T_Day = x / Dim_Righe;
    cout<<"La temperadura di "<<Giorno<<" e uguale a: "<<T_Day<<"°"<<endl;
}
    cout<<T_Week<<endl;
    T_Week = T_Week / (Dim_Collonne * Dim_Righe);
    cout<<"La temperatura di tutta la settimana corrisponde a: "<<T_Week<<"°"<<endl;
}
