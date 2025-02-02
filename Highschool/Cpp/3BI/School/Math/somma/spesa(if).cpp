#include <iostream>
using namespace std;

int main() {
	float spesa;
	cout<<"inserisci la spesa"<<endl;
	cin>>spesa;
	if (spesa>=200) {
		spesa=spesa-10;
	}
	else if (spesa>=100) {
		spesa=spesa-5;
	}
	else{
		cout<<"no sconto"<<endl;
	}
	cout<<"la spesa e uguale a:"<<spesa<<endl;
	return 0;
}
