#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int MaxGrade = 10;

class Temperature{
    float grade[MaxGrade], minT, maxT;

    public:
        void input(){
            for (int i=0; i<MaxGrade; i++){
                cout<<"Day " <<i+1 <<", input a temperature: ";
                cin>>grade[i];
            }
        }
        void overZero(){
            for (int i=0; i<MaxGrade; i++)
                if (grade[i] >= 0)
                    cout<<"Day " <<i+1 
                        <<", temperature: " <<grade[i] <<endl;
        }
        float maxminSearch(){
            maxT = *max_element(grade, grade + MaxGrade);
            minT = *min_element(grade, grade + MaxGrade);
            cout<<"The hottest texperature was: " <<maxT <<endl;
            cout<<"The coldest temperature was: " <<minT <<endl;
        }
        float contAverage(){
            float average = 0;
            for (int i=0; i<MaxGrade; i++)
                average +=grade[i];
            return average;
        }
        void averagePlus(){
            float average = contAverage();
            average /= MaxGrade;
            cout<<"Average plus:" <<endl;
            for (int i=0; i<MaxGrade; i++)
                if (grade[i] >= average)
                    cout<<"Day: " <<i+1 <<", temperature: " <<grade[i] <<endl;
        }
};


int main(){
    Temperature newTemperature;

    newTemperature.input();

    int option;
    do{
        cout<<"Menu:" <<endl
            <<" 0 - Exit" <<endl
            <<" 1 - Print temperatures wich are over 0." <<endl
            <<" 2 - Print max and min temperatures." <<endl
            <<" 3 - Print all temperatures wich are over average." <<endl
            <<"Option: ";
        cin>>option;
        cout<<endl;
        switch(option){
            case 0:
                cout<<"EXIT" <<endl;
            break;
            case 1:
                newTemperature.overZero();
            break;
            case 2:
                newTemperature.maxminSearch();
            break;
            case 3:
                newTemperature.averagePlus();
            break;
            default:
                cout<<"Retry..." <<endl;
            break;
        }
    } while (option != 0);
    return 0;
}