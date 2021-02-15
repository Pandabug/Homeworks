#include<iostream>
using namespace std;

int main(){
	int d[]={};
	int n,r,cont=2,con=0;
		for(int i=0;i<100;i++){
			while(cont<i && r!=0){
		r=n%i;
			if(r==0){
			cont++;
			d[con]=i;
		}
	}
}
	for(int i=0;i<con;i++){
		cout<<d<<endl;
	}
return 0;
}
