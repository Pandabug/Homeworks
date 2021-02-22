#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

struct Products{
    string ProductCod;
    string ProductName;
    int ProductQuantity;
    float ProductPrice;
};

class Shop{
    vector <Products> SingleProduct;
    Products newProduct;
    
    public:
        void input(){
            //File
            fstream MyFile;

            //Open a file
            MyFile.open("FileProducts.txt", ios::in);

            while (!MyFile.eof()){
                MyFile >>newProduct.ProductCod 
                       >>newProduct.ProductName 
                       >>newProduct.ProductQuantity 
                       >>newProduct.ProductPrice;
                SingleProduct.push_back(newProduct);
            }
            MyFile.close();
        }
        //search a product cod and return her position
        float searchProduct(string SearchCod){
            int position = -1;
            

            for(int i=0; i<SingleProduct.size(); i++)
                if (SingleProduct[i].ProductCod == SearchCod){
                    position = i;
                    break;
                }
            return position;
        }
        //change quantity of the product with replacement of the old quantity
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
        //to add new product
        void addProduct(string newCod){
            newProduct.ProductCod = newCod;
            cout<<"Name: ";
            cin>>newProduct.ProductName;
            cout<<"Quantity: ";
            cin>>newProduct.ProductQuantity;
            cout<<"Price: ";
            cin>>newProduct.ProductPrice;
            SingleProduct.push_back(newProduct);
        }
        //print the list of the products
        void printData(){
            sort();
            for (int i=0; i<SingleProduct.size(); i++)
                cout<<"Cod: " <<SingleProduct[i].ProductCod <<endl
                    <<"Name: " <<SingleProduct[i].ProductName <<endl
                    <<"Quantity: " <<SingleProduct[i].ProductQuantity <<endl
                    <<"Price: "  <<SingleProduct[i].ProductPrice <<endl <<endl;
        }
        //sort the list of items befor print
        void sort(){
            Products tmp;
            for (int i=0; i<SingleProduct.size()-1; i++)
                for (int j=i+1; j<SingleProduct.size(); j++)
                    if(SingleProduct[i].ProductCod > SingleProduct[j].ProductCod){
                        tmp = SingleProduct[i];
                        SingleProduct[i] = SingleProduct[j];
                        SingleProduct[j] = tmp;
                    }
        }
        //delete item from the list of product
        void deleteProduct(){
            string SearchCod;

            cout<<"Input a cod of the product: ";
            cin>>SearchCod;
            int position = searchProduct(SearchCod);
            if (position == -1) cout<<"Cod not find." <<endl;
            else{
                for (int i=position; i<SingleProduct.size(); i++)
                    SingleProduct.erase(SingleProduct.begin() + position);
                    
            }
        }
};

int main(){
    Shop newShop;

    newShop.input();

    int option;
    do{
        //menu
        cout<<endl <<"Menu:" <<endl
            <<" - 0 EXIT." <<endl
            <<" - 1 To chenge quantity." <<endl
            <<" - 2 Print the lsit." <<endl
            <<" - 3 To delete from the list." <<endl
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
            case 3:
                newShop.deleteProduct();
            break;
            default:
                cout<<"Retry..." <<endl;
            break;
        }
    } while (option != 0);
    return 0;
}