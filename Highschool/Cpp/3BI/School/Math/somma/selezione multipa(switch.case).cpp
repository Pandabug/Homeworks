#include<iostream>
using namespace std;
int main(){
	float a,b,ris;
	char op;
	cout<<"inserisci"<<endl;
	cin>>a;
	cin>>b;
	cout<<"op"<<endl;
	cin>>op;
	switch(op){
		case'+':
		ris=a+b;
		cout<<"somma"<<ris<<endl;
		break;
		case'-':
		ris=a-b;
		cout<<"differenza"<<ris<<endl;
		break;
		case'*':
		ris=a*b;
		cout<<"moltiplicazione"<<ris<<endl;
		break;
		case'/':
		if(b==0){
		cout<<"errore"<<endl;
		}
		else{
		ris=a/b;
		cout<<"divisione"<<ris<<endl;
		}
		break;
		default:
		cout<<"op nn esis"<<endl;
		break;
	}
	return 0;
}
