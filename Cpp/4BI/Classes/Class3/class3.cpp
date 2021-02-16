#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const int MaxProduct = 100;
int CurrentProduct = 0;

struct Products{
    string ProductCod;
    string ProductName;
    int ProductQuantity;
    float ProductPrice;
};

class Shop{
    Products SingleProduct[MaxProduct];
    
    public:
        void input(){
            //File
            fstream MyFile;

            //Open a file
            MyFile.open("FileProducts.txt", ios::in);

            while (!MyFile.eof()){
                MyFile >>SingleProduct[CurrentProduct].ProductCod >>SingleProduct[CurrentProduct].ProductName >>SingleProduct[CurrentProduct].ProductQuantity >>SingleProduct[CurrentProduct].ProductPrice;
                CurrentProduct++;
            }
        }
        float searchProduct(string SearchCod){
            int position = -1;
            

            for(int i=0; i<CurrentProduct; i++)
                if (SingleProduct[i].ProductCod == SearchCod){
                    position = i;
                    break;
                }
            return position;
        }
        void ChangeQuantity(){
            string SearchCod;

            cout<<"Input a cod of the product: ";
            cin>>SearchCod;
            int position = searchProduct(SearchCod);
            if (position == -1){
                int option;
                cout<<"Cod not find, u want to add it to this product list? (no/0 yes/1): ";
                cin>>option;
                if (option == 1) addProduct(SearchCod);
                else cout<<"Cod not find."<<endl;
            }
            else{
                int newQuantity;

                cout<<"Current quantity: " <<SingleProduct[position].ProductQuantity <<", input a new quantity: ";
                cin>>newQuantity;
                
                SingleProduct[position].ProductQuantity = newQuantity;
            }
        }
        void addProduct(string newCod){
            SingleProduct[CurrentProduct].ProductCod = newCod;
            cout<<"Name: ";
            cin>>SingleProduct[CurrentProduct].ProductName;
            cout<<"Quantity: ";
            cin>>SingleProduct[CurrentProduct].ProductQuantity;
            cout<<"Price: ";
            cin>>SingleProduct[CurrentProduct].ProductPrice;
            CurrentProduct++;
        }
        void printData(){
            for (int i=0; i<CurrentProduct; i++)
                cout<<"Cod: " <<SingleProduct[i].ProductCod <<endl
                    <<"Name: " <<SingleProduct[i].ProductName <<endl
                    <<"Quantity: " <<SingleProduct[i].ProductQuantity <<endl
                    <<"Price: "  <<SingleProduct[i].ProductPrice <<endl <<endl;
        }
        // void order(){}
};

int main(){
    Shop newShop;

    newShop.input();

    int option;
    do{
        cout<<endl <<"Menu:" <<endl
            <<" - 0 EXIT." <<endl
            <<" - 1 To chenge quantity." <<endl
            <<" - 2 Print the lsit." <<endl
            <<"Option: ";
        cin>>option;
        cout<<endl;
        switch(option){
            case 0:
                cout<<"EXIT" <<endl;
            break;
            case 1:
                newShop.ChangeQuantity();
            break;
            case 2:
                newShop.printData();
            break;
            default:
                cout<<"Retry..." <<endl;
            break;
        }
    } while (option != 0);
    return 0;
}