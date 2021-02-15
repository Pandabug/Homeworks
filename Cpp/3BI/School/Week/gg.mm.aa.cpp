#include<iostream>
using namespace std;
int main(){
	int gg,mm;
	cout<<"inseriaci il mese"<<endl;
	cin>>mm;
	cout<<"inserisci il giorno"<<endl;
	cin>>gg;
	
	if(mm>0 && mm<=12){
		if(mm==2 && gg>0 && gg<=28){
		cout<<"ok"<<endl;
	}
	else{if((mm==1 || mm==3 || mm==5 || mm==7 ||mm==8 || mm==10 || mm==12)&& gg>0 && gg<=31){
		cout<<"ok"<<endl;
	}
	else{if((mm==4 || mm==6 || mm==9 || mm==11)&& gg>0 && gg<=30){
		cout<<"ok"<<endl;
	}
	else{
		cout<<"SBAGLIATO"<<endl;
	}
	}
	}
	}
	else{
		cout<<"SBAGLIATO"<<endl;
	}

return 0;
}
