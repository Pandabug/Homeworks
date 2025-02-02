#include<iostream>
using namespace std;
int main(){
	int n,r,v,neg,i;
	neg=0;
	r=0;
	v=0;
	do{
		v+=1;
		cout<<"inserisci il numero"<<endl;
		cin>>n;
		i=n%2;
		if(i==0){
			r=r+n;
		}
		else{
			neg+=1;
		}
	}
	while(v<10);
	cout<<"somma dei valori positivi "<<r<<endl;
	cout<<"numeri dispari sono "<<neg<<endl;
return 0;
}
