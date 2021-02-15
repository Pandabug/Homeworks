#include <iostream>
using namespace std;

int main(){
    int m, n maxx=0, maxy=0;
    
    cout<<"Input a max line number: ";
    cin>>n;
    cout<<"Input a max column number: ";
    cin>>m;
    cout<<endl;
    
    float Media=0;
    float A[m][n];
    for (int x=0; x<m; x++){
        float b=0;
        maxx=0;
        maxy=0;
        for (int y=0; y<n; y++){
            //input
            cout<<"Colonna n°"<<x+1<<" riga n° "<<y+1<<" Input number: ";
            cin>>A[x][y];
            //trova il massimo
            if (A[x][y]>A[maxx][maxy]){
                maxx=x;
                maxy=y;
            }
        }
        cout<<"Colonna n°"<<x+1<<" il valore massimo e: "<<A[maxx][maxy]<<endl;
        //media di ogni colonna
        for (int y=0; y<n; y++){
            b+=A[x][y];
        }
        Media=b/n;
        cout<<Media<<endl;
    }
//prova stampa tutti i numeri inseriti
    cout<<endl<<"Numbers u use before: "<<endl;
    for (int x=0; x<m; x++){
        for (int y=0; y<n; y++){
            cout<<A[x][y]<<"\t";
        }
        cout<<endl;
    }
//stampa minimo
int minx=0,miny=0;
    for (int x=0; x<m; x++){
        for (int y=0; y<n; y++){
            if (A[x][y]<A[minx][miny]){
                minx=x;
                miny=y;
            }
        }
    }
    cout<<"Il valore minimo e: "<<A[minx][miny]<<endl;
}
