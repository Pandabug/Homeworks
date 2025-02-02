#include<iostream>
using namespace std;

int main(){
	int n,d,cont;
	cont=0;
	cout<<"inserisci il numero"<<endl;
	cin>>n;
	if(n<=100){
		for(int i=2;i<n;i++){
		d=n%i;
			if(d==0){
			cont++;
		}
	}
	if(cont>=1){
		cout<<"non e un numero primo"<<endl;
	}
	else{
		cout<<"e un numero primo"<<endl;
	}
	}
	else{
		cout<<"il numero e superiore a 100"<<endl;
	}
return 0;
}
