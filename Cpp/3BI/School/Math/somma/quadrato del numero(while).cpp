#include<iostream>
using namespace std;
int main(){
	float n,r;
	r=0;
	while(n>0 || n<-1){
		cout<<"inserisci n"<<endl;
		cin>>n;
		r=n*n;
		cout<<r<<endl;
	}
	return 0;
}
