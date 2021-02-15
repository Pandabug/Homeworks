#include<iostream>
using namespace std;

int main(){
	int n,r,v,neg;
	neg=0;
	cout<<"quanti valori vuoi inserire"<<endl;
	cin>>v;

	for(int i=0;i<v;i++){
		cout<<"inserisci i valori positivi e negativi"<<endl;
		cin>>n;
		if(n>0){
			r=r+n;
		} else if(n<0){
			neg=neg+1;
		}
	}
	cout<<"somma dei valori positivi "<<r<<endl;
	cout<<"valori negativi sono "<<neg<<endl;
return 0;
}
