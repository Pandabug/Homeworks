#include<iostream>
#include<string>
using namespace std;

int main(){
    string c,cog;
    int e,b,min,p;
    cout<<""<<endl;
    cin>>b;
    cout<<"cognome ed eta"<<endl;
    cin>>c;
    cin>>e;
    min=e;
    cog=c;
    p=1;
    for(int i=2;i<b;i++){
        string cd;
        int ed;
        cout<<"cognome ed eta"<<endl;
        cin>>cd;
        cin>>ed;
            if(ed<e){
            min=ed;
            cog=cd;
            p=i;
        }
    }
    cout<<"studente "<<cog<<" di eta "<<min<<" in posizione "<<p<<endl;
 return 0;
}
