#include<iostream>
using namespace std;
int main(){
	for(int i=100;i<201;i++){
		int a=i%3;
		int b=i%2;
		if(a==0 && b!=0){
			cout<<i<<endl;
		}
	}
	return 0;
}
