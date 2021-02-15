#include <iostream>
#include <string>
using namespace std;
string titolo[10];
int incasso[10];

void carica(int max){
	for(int i=0;i<max;i++){
		cout<<"Inserire titolo del film "<<i<<endl;
		cin>>titolo[i];
		cout<<"Inserire incasso del film "<<i<<endl;
		cin>>incasso[i];
	}
}

void stampa(int max){
	for(int i=0;i<max;i++)
		cout<<"Titolo e incasso film "<<i<<" = "<<titolo[i]<<" con incasso = "<<incasso[i]<<endl;
}

void stampaval(int max){
	int val;
	cout<<"Inserire valore"<<endl;
	cin>>val;
	cout<<"Film con incasso maggiore del valore inserito:"<<endl;
	for(int i=0;i<max;i++){
		if(incasso[i]>val){
			cout<<titolo[i]<<" con incasso = "<<incasso[i]<<endl;
		}
	}
}

int stampamax(int max){
	int pos;
	for(int i=0;i<max;i++){
		if(incasso[i]>incasso[i+1])
			pos=i;
	}
	return pos;
}
int main(){
	int n;
	do{
	cout<<"Inserire numero di film (max 100): ";
	cin>>n;
	}
	while(n<0);
	carica(n);
	int m,pos;
	do{
		cout<<""<<endl;
		cout<<"Inserire numero per scegliere"<<endl;
		cout<<"Scelta 1: stampa film"<<endl;
		cout<<"Scelta 2: stampa maggiori di val"<<endl;
		cout<<"Scelta 3: stampa film con piu incassi"<<endl;
		cout<<"Premere un qualunque altro numero per chiudere"<<endl;
		cin>>m;
		cout<<""<<endl;
		switch(m){
			case 1:
				stampa(n);
			break;
			case 2:
				stampaval(n);
			break;
			case 3:
				pos = stampamax(n);
				cout<<"Film con maggiore incasso = "<<titolo[pos]<<", "<<incasso[pos]<<endl;
			break;
			default:
				cout<<"chiusura in corso"<<endl;
		}
	}
	while(m>0 && m<=3);
}
