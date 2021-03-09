#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Grounds{
    string code;
    float extension;
    float building_percentage;
    float income_sqm;
};

class Ground{
    vector<Grounds> singleGround;
    Grounds newGround;
    float media = 0;

    public:
        void input(){
            cout<<"Input code : ";
                cin>>newGround.code;
            cout<<"Input extension : ";
                cin>>newGround.extension;
            cout<<"Input building percentage : ";
                cin>>newGround.building_percentage;
            cout<<"Input income sqm : ";
                cin>>newGround.income_sqm;
                    media += newGround.income_sqm;

            singleGround.push_back(newGround);
        }
        int searchGround(){
            int position = -1;
            string searchGroundName;

            cout<<"Input a thain to search: ";
            cin>>searchGroundName;

            for (int i=0; i<singleGround.size(); i++)
                if (singleGround[i].code == searchGroundName){
                    position = i;
                    break;
                }
                
            return position;
        }
        void maxSqm(){
            float extensionEl = 0;
            int position;

            for (int i=0; i<singleGround.size(); i++)
                if(singleGround[i].extension > extensionEl){
                    extensionEl = singleGround[i].extension;
                    position = i;
                }

            cout<<endl <<"Ground: " <<singleGround[position].code <<" with " <<singleGround[position].extension <<" sqm." <<endl <<endl;
        }
        void averageIncome(){
            media /= singleGround.size();

            cout<<"The Grounds rent average is equal to: " <<media <<endl;
        }
};

int main(){
    Ground newGround;

    newGround.input();

    int option;
    do{
        cout<<"Menu:" <<endl
            <<" - 0 EXIT." <<endl
            <<" - 1 Input a new Ground." <<endl
            <<" - 2 Max of sqm." <<endl
            <<" - 3 For average income." <<endl
            <<"Option: ";
            cin>>option;
        switch (option){
            case 0:
                cout<<"EXIT" <<endl;
            break;
            case 1:
                newGround.input();
            break;
            case 2:
                newGround.maxSqm();
            break;
            case 3:
                newGround.averageIncome();
            break;
            default:
                cout<<"Retry..." <<endl;
            break;
        }
    } while (option != 0);
}