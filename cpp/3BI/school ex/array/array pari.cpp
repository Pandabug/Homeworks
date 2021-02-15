#include <iostream>
using namespace std;

int main(){
	int v[5],n,d,index=0;
	for(int i=0;i<5;i++){
		cout<<"inserisci i valori"<<endl;
		cin>>n;
		d=n%2;
		if(d==0){
			v[index]=n;
			index++;
		}
	}
	if(index!=0){
		for(int i=0;i<index;i++){
			cout<<v[i]<<endl;
		}
	}
	else{
		cout<<"non ci sono numeri pari"<<endl;
	}
return 0;
}
