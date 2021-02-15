#include<iostream>
using namespace std;
int main(){
float n,r,media,rr;
int b;
cin>>b;
	for(int i=0;i<b;i++){
	cout<<"inserisci i valori"<<endl;
	cin>>n;
	r=r+n;
	}
	media=r/b;
		for(int a=0;a<b;a++){
		cout<<"inserisci i valori"<<endl;
		cin>>n;
		if(n>media){
			rr=rr+n;
		}
		else{
		}
	}
cout<<"risultato della somma "<<r<<endl;
cout<<"media "<<media<<endl;
cout<<"la somma dei numeri maggiori della  media e "<<rr<<endl;
return 0;
}
