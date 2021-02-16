#include <iostream>
using namespace std;

int main(){
    float n,mag,min,t[31];
    for(int i=0;i<31;i++){
        cout<<"inserisic la temperatura del giorno "<<i+1<<endl;
        cin>>n;
        t[i]=n;
    }
        mag=t[0];
        min=t[0];
    for(int i=0;i<31;i++){
       if(t[i]>mag){
        mag=t[i];
       }
       else if(t[i]<min){
            min=t[i];
       }
    }
    cout<<"la temperatura del giorno piu caldo e "<<mag<<endl;
    cout<<"la temperatura del giorno piu freddo e "<<min<<endl;
return 0;
}
