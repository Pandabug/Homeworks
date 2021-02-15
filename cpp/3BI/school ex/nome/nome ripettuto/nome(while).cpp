#include<iostream>
#include<string>
using namespace std;
int main(){
	string n;
	int i,a;
	cout<<"inserisci il nome"<<endl;
	cin>>n;
	cout<<"per quante volte"<<endl;
	cin>>a;
	i=1;
	while(i<=a){
		cout<<n<<endl;
		i++;
	}	
return 0;
}
