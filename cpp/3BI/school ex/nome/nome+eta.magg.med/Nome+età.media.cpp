#include<iostream>
#include<string>
using namespace std;
int main(){
	string n1,n2,n3;
	int e1,e2,e3;
	cout<<"inserisci i nomi"<<endl;
	cin>>n1;
	cin>>n2;
	cin>>n3;
	cout<<"inserisci l'eta"<<endl;
	cin>>e1;
	cin>>e2;
	cin>>e3;
	if(e1<100 && e2<100 && e3<100){
	if((e1>e2 && e1<e3) || (e1<e2 && e1>e3)){
		cout<<n1<<endl;
	}
	else if((e2>e1 && e2<e3) || (e2<e1 && e2>e3)){
	cout<<n2<<endl;
}
	else{
		cout<<n3<<endl;
	}
	}
	else{
		cout<<"Non e possibile avere piu di 100 anni"<<endl;
	}
	return 0;
}
