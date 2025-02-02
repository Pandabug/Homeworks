#include<iostream>
using namespace std;
int main(){
	float a,b,c;
	cout<<"inserisci i tre valori"<<endl;
	cin>>a;
	cin>>b;
    cin>>c;

if(a==b && b==c){
	cout<<"equilatero"<<endl;
} else if(a==b || b==c || c==a){
	cout<<"isoscere"<<endl;
	} else{
		cout<<"scaleno"<<endl;
		}
return 0;
}
