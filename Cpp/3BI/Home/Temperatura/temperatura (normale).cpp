#include<iostream>
using namespace std;

void test(){
	float ma,mi,t1;
	for(int i=1;i<32;i++){
		cout<<"inserici la temperatura del giorno "<<i<<endl;
		cin>>t1;
		if(t1>ma){
			ma=t1;
		}
		if(t1<mi){
			mi=t1;
		}
	}
	cout<<"la temperatura maggiore e "<<ma<<endl;
	cout<<"la temperatura minore e "<<mi<<endl;
}

int main(){
	float t,ma,mi;
	cout<<"inserici la temperatura del giorno 1"<<endl;
	cin>>t;
	mi=t;
	ma=t;
	test();
}
