#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Ground{
    string newCode;
    float newExtension;
    float newBuilding_percentage;
    float newIncome_sqm;

    public:
        Ground(string code, float extension, float building_percentage, float income_sqm){
            newCode = code;
            newExtension = extension;
            newBuilding_percentage = building_percentage;
            newIncome_sqm = income_sqm;
        }
        string getCode(){
            return newCode;
        }
        float groundAverage(){
            return newExtension * newIncome_sqm;
        }
        float ground_sqm(){
            return newExtension/100 * newBuilding_percentage;
        }
        void print(){
            cout<<"Code : " <<newCode <<endl
                <<"Extension : " <<newExtension <<endl
                <<"Building percentage : " <<newBuilding_percentage <<endl
                <<"Income sqm : " <<newIncome_sqm <<endl <<endl;

        }
};

int main(){
    vector<Ground> singleGround;

    int option;
    do{
        cout<<"Menu:" <<endl
            <<" - 0 EXIT." <<endl
            <<" - 1 Input a new Ground." <<endl
            <<" - 2 Gound extension." <<endl
            <<" - 3 Ground percentage." <<endl
            <<" - 4 Ground info." <<endl
            <<"Option: ";
            cin>>option;
            cout<<endl;
        switch (option){
            case 0:
                cout<<"EXIT" <<endl;
            break;
            case 1:{
                string code;
                float extension, building_percentage, income_sqm;

                cout<<"Input code : ";
                    cin>>code;
                cout<<"Input extension : ";
                    cin>>extension;
                cout<<"Input building percentage : ";
                    cin>>building_percentage;
                cout<<"Input income sqm : ";
                    cin>>income_sqm;

                singleGround.push_back(Ground(code, extension, building_percentage, income_sqm));
            }
            break;
            case 2:{
                string searchGroundName;

                cout<<"Input a thain to search: ";
                cin>>searchGroundName;

                for (int i=0; i<singleGround.size(); i++)
                    if (singleGround[i].getCode() == searchGroundName) 
                        cout<<"The Grounds rent average is equal to: " <<singleGround[i].groundAverage() <<endl;
            }
            break;
            case 3:{
                string searchGroundName;

                cout<<"Input a thain to search: ";
                cin>>searchGroundName;

                for (int i=0; i<singleGround.size(); i++)
                    if (singleGround[i].getCode() == searchGroundName) 
                        cout<<"The building percentage of the land is " <<singleGround[i].ground_sqm() <<"%" <<endl;
            }
            break;
            case 4:{
                string searchGroundName;

                cout<<"Input a thain to search: ";
                cin>>searchGroundName;

                for (int i=0; i<singleGround.size(); i++)
                    if (singleGround[i].getCode() == searchGroundName) 
                        singleGround[i].print();
            }
            break;
            default:
                cout<<"Retry..." <<endl;
            break;
        }
    } while (option != 0);
}