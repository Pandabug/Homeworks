#include <iostream>
using namespace std;
int main()
{
int i;
float t,tmax,tmin,t1;
cout<<"inserisci la prima temperatura"<<endl;
cin>>t1;
tmax=t1; 
tmin=t1;
for(i=2;i<=5;i++){
	cout<<"inserisci temperatura giorno:"<<i<<endl;
	cin>>t;
	if(t>tmax){
		tmax=t;
	}
	if(t<tmin){
		tmin=t;
	}	
}
cout<<"temperatura max="<<tmax<<endl;
cout<<"temperatura min="<<tmin<<endl;
}
