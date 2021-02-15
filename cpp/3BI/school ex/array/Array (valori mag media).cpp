#include<iostream>
using namespace std;

int main(){
	int v[10],s=0;
	float m;
	for(int i=0;i<10;i++){
		cout<<"inserisci i numeri"<<i+1<<endl;
		cin>>v[i];
		s+=v[i];
	}
	m=s/10;
	for(int i=0;i<10;i++){
		if(v[i]>m){
			cout<<v[i]<<endl;
		}
	}
	return 0;
}
