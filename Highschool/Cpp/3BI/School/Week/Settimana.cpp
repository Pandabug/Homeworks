#include<iostream>
#include<string>
using namespace std;
int main(){
	string g;
	cout<<"inserisci il giorno"<<endl;
	cin>>g;
	if(g=="Lunedi"){
		cout<<"1"<<endl;
		}
		else{
			if(g=="Martedi"){
			cout<<"2"<<endl;
			}
			else{
				if(g=="Mercoledi"){
				cout<<"3"<<endl;
				}
				else{
					if(g=="Giovedi"){
					cout<<"4"<<endl;
					}
					else{
						if(g=="Venerdi"){
						cout<<"5"<<endl;
						}
						else{
							if(g=="Sabato"){
							cout<<"6"<<endl;
							}
							else{
								if(g=="Domenica"){
								cout<<"7"<<endl;
								}
								else{
								cout<<"ERRORE"<<endl;
							}	
						}
					}
				}
			}
		}
	}
	return 0;
}