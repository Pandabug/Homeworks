#include <iostream>
using namespace std;

int main(){
    int n,d,cont;
	cont=0;
    cin>>n;
    for(int i=2;i<n;i++){
        d=n%i;
        if(d==0){
            cont++;
        }
    }
    if(cont!=0){
        cout<<"non e un numero primo"<<endl;
    }
    else{
        cout<<"e un numero primo"<<endl;
    }
return 0;
}
