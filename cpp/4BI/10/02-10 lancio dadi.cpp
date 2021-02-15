#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main(){
    srand(time(0));
    int n;
    float cont1=0,cont2=0,cont3=0,cont4=0,cont5=0,cont6=0,r1=0,r2=0,r3=0,r4=0,r5=0,r6=0;
    const int Max_Dim=15;
    for (int i=0; i<Max_Dim; i++){
        n=(rand()%6)+1;
        cout<<n<<endl;
        switch (n){
        case 1:
            cont1++;
            break;
        case 2:
            cont2++;
            break;
        case 3:
            cont3++;
            break;
        case 4:
            cont4++;
            break;
        case 5:
            cont5++;
            break;
        case 6:
            cont6++;
            break;
        }
    }
    r1=(cont1/Max_Dim)*100;
    r2=(cont2/Max_Dim)*100;
    r3=(cont3/Max_Dim)*100;
    r4=(cont4/Max_Dim)*100;
    r5=(cont5/Max_Dim)*100;
    r6=(cont6/Max_Dim)*100;

cout<<"Faccia 1: "<<r1<<"%"<<endl;
cout<<"Faccia 2: "<<r2<<"%"<<endl;
cout<<"Faccia 3: "<<r3<<"%"<<endl;
cout<<"Faccia 4: "<<r4<<"%"<<endl;
cout<<"Faccia 5: "<<r5<<"%"<<endl;
cout<<"Faccia 6: "<<r6<<"%"<<endl;
}