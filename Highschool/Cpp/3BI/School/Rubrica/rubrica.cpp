#include <iostream>
#include <string>
using namespace std;

int main(){
	int tel[100],tell,s,in=0,telc,cont;
	string cog[100],cogn,cogc;
	bool c=false;
		cout<<"scegli tra: "<<endl;
		cout<<" -0: spegni"<<endl;
		cout<<" -1: inserisci"<<endl;
		cout<<" -2: stampa"<<endl;
		cout<<" -3: cerca"<<endl;
		cout<<" -4: elimina dalla rubrica"<<endl;
		cout<<endl;
	do{
		cout<<endl;
		cout<< "Selezionare l'opzione desiderata: ";
		cin>>s;
		switch(s){
			case 1:
				cout<<"cognome :";
				cin>>cogn;
				cog[in]=cogn;
				cout<<"numero di telefono :";
				cin>>tell;
				tel[in]=tell;
				in++;
				break;
			case 2:
				for(int i=0;i<in;i++){
					cout<<"cognome :"<<cog[i];
					cout<<" numero di telefono :"<<tel[i]<<endl;
					cout<<endl;
					}
				break;
			case 3:
				cout<<"metti il cognome ";
				cin>>cogc;
					for(int i=0;i<in;i++){
						if(cogc==cog[i]){
							c=true;
							telc=i;
						}
					}
					if(c==true){
						cout<<"numero di telefono di "<<cog[telc]<<" e "<<tel[telc]<<endl;
					}
					else{
						cout<<"non e presente nella rubrica"<<endl;
					}
					break;
				case 4:
					cout<<"Inserire il cognome del contatto da eliminare: ";
					cin>>cogc;
						for (int i=0;i<in;i++){
							if(cogc==cog[i]){
								c=true;
								cont=i;
							}
						}
						if(c==true){
							for(int d=cont;d<in;d++){
								cog[d]=cog[d+1];
								tel[d]=tel[d+1];
							}
							in--;
						} else{
							cout<<"Contatto non presente.";
							}
						break;
					default:
						cout<<"opzione non presente"<<endl;
				}
			}
	while(s!=0);
return 0;
}
