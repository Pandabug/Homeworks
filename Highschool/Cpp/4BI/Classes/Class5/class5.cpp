#include <iostream>
#include <string>
using namespace std;

const int MaxNum = 10;
int contShop = 0;
int contProd = 0;

struct ShopN{
    struct products{
        string name;
        int departmentsNumber;
        string departments;
        float recessed;
    };
    products newProduct[MaxNum];
    string shopName;
};

class Shop{
    ShopN newShop[MaxNum];

    public:
        void inputShopName(){
            cout<<"Input a shop name: ";
            cin>>newShop[contShop].shopName;
            contShop++;
        }
        int searchShop(){
            int position = -1;
            string searchShopName;

            cout<<"Input a Shop Name to search: ";
            cin>>searchShopName;
            
            for (int i=0; i<contShop; i++)
                if (newShop[i].shopName == searchShopName){
                    position = i;
                    break;
                }

            return position;
        }
        void input(){
            int position = searchShop();

            if(position == -1) cout<<"Shop not find." <<endl;
            else{
                cout<<"Input products name: ";
                cin>>newShop[position].newProduct[contProd].name;
                cout<<"Input product number of departaments: ";
                cin>>newShop[position].newProduct[contProd].departmentsNumber;
                cout<<"Input product departaments: ";
                cin>>newShop[position].newProduct[contProd].departments;
                cout<<"Input product recessed: ";
                cin>>newShop[position].newProduct[contProd].recessed;
                
                contProd++;
            }
        }
        void print(){
            for (int i=0; i<contShop; i++){
                cout<<"Shop Name: " <<newShop[i].shopName <<endl;
                for (int j=0; j<contProd; j++){
                    if (newShop[i].newProduct[j].name != "")
                        cout<<" - Name: " <<newShop[i].newProduct[j].name <<endl
                            <<" - Number of departments: " <<newShop[i].newProduct[j].departmentsNumber <<endl
                            <<" - Departments: " <<newShop[i].newProduct[j].departments <<endl
                            <<" - Recessed: " <<newShop[i].newProduct[j].recessed <<endl <<endl;
                }
            }
        }
        void annuity(){
            for (int i=0; i<contShop; i++){
                float average = 0;
                for (int j=0; j<contProd; j++)
                    if (newShop[i].newProduct[j].name != "")
                        average += newShop[i].newProduct[j].recessed;
                cout<<"L'incasso del supermercato "<<newShop[i].shopName <<", e uguale a: "<<average <<endl;
            }
        }
        void searchDepartments(){
            int position1;
            int position2;
            bool check = false;
                
            string searchDepartmentsName;

            cout<<"Input a Department Name to search: ";
            cin>>searchDepartmentsName;
            
            for (int i=0; i<contShop; i++)
                for (int j=0; j<contProd; j++)
                    if (newShop[i].newProduct[j].departments == searchDepartmentsName){
                        position1 = i;
                        position2 = j;
                        check = true;
                    }

            if (check) cout<<"Recessed: " <<newShop[position1].newProduct[position2].recessed <<endl;
            else cout<<"Departments not find." <<endl;
        }
};

int main(){
    Shop shopCenter;

    shopCenter.inputShopName();

    int option;
    do{
        cout<<endl <<"Menu:" <<endl
            <<" - 0 EXIT." <<endl
            <<" - 1 To add new shop." <<endl
            <<" - 2 To add a product." <<endl
            <<" - 3 Print data." <<endl
            <<" - 4 Print annuity." <<endl
            <<" - 5 Departments" <<endl
            <<"Option: ";
        cin>>option;
        cout<<endl;
        switch(option){
            case 0:
                cout<<"EXIT" <<endl;
            break;
            case 1:
                shopCenter.inputShopName();
            break;
            case 2:
                shopCenter.input();
            break;
            case 3:
                shopCenter.print();
            break;
            case 4:
                shopCenter.annuity();
            break;
            case 5:
                shopCenter.searchDepartments();
            break;
            default:
                cout<<"Retry..." <<endl;
            break;
        }
    } while (option != 0);
    return 0;
}
