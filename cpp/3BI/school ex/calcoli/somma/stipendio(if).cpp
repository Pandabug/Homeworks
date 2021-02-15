#include<iostream>
using namespace std;
int main() {
int NF;
float SL,SN;
cout<<"inserici il tuo stipendio"<<endl;
	cin>>SL;
cout<<"inserisci il n dei figli"<<endl;
	cin>>NF;
if(NF>0){
SL=SL+1000;}
	if(SL>20000){
	SN=SL-0.2*SL;
		}
	else {
	SN=SL-0.1*SL;
		}
	cout<<"stipendio netto="<<SN<<endl;
return 0;
}
