#include<iostream>
#include<string>
using namespace std;
int main(){
	int i,a;
	string n;
	cout<<"inserisci il nome"<<endl;
	cin>>n;
	cout<<"per quante volte"<<endl;
	cin>>a;
	i=0;
	do{
		cout<<n<<endl;
		i++;
	}
	while(i<a);
	return 0;
}
