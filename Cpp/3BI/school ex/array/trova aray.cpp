#include <iostream>
using namespace std;

int main(){
	int v[10];
	bool c=false;
	int num,pos=0;
	for (int i=0;i<10;i++){
		cout<<"Inserire il numero in posizione "<<i+1<<endl;
		cin>>v[i];
	}
	cout<<"---Inserire il numero da confrontare---"<<endl;
	cin>>num;
	for (int i=0;i<10;i++){
		if (num==v[i]){
			c=true;
			pos=i;
		}
	}
	if(c){
		cout<<"Il numero si trova in posizione " <<pos+1 <<endl;
	}
	else{
		cout<<"Il numero non e' presente nell'array.";
	}
	return 0;
}
