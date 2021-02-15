#include<iostream>
using namespace std;
int main(){
	int n,r;
	for(int i=20;i<=100;i++){
		n=i%5;
		if(n==0){
		r=r+i;
	}
	}
	cout<<r<<endl;
return 0;
}
