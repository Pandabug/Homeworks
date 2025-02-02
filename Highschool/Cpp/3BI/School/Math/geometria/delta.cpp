#include<iostream>
#include<cmath>
using namespace std;
int main(){
	float a,b,c,x1,x2,ris,delta;
	
	cout<<"inserisci i tre valori"<<endl;
	cin>>a;
	cin>>b;
	cin>>c;
	
	delta=b*b-4*a*c;
	
	if(delta==0){
		ris=(-b)/(2*a);
		cout<<ris<<endl;
	} else if(delta>0){
			x1=(-b+sqrt(delta))/(2*a);
			x2=(-b-sqrt(delta))/(2*a);
			cout<<"Soluzine "<<x1<<endl;
			cout<<"Soluzione "<<x2<<endl;
			} else{
				cout<<"non ha soluzioni"<<endl;
				}
return 0;
}
