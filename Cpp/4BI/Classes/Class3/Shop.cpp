#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

struct Products{
    string ProductCode;
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
                MyFile >>newProduct.ProductCode 
                       >>newProduct.ProductName 
                       >>newProduct.ProductQuantity 
                       >>newProduct.ProductPrice;
                SingleProduct.push_back(newProduct);
            }
            MyFile.close();
        }
        string getCode(){
            string SearchCode;
            
            cout<<"Input a cod of the product: ";
            cin>>SearchCode;

            return SearchCode;
        }
        //search a product cod and return her position
        float searchProduct(){
            int position = -1;
            string searchCode = getCode();

            for(int i=0; i<SingleProduct.size(); i++)
                if (SingleProduct[i].ProductCode == searchCode){
                    position = i;
                    break;
                }
            return position;
        }
        //change quantity of the product with replacement of the old quantity
        void ChangeQuantity(){
            int position = searchProduct();
            if (position == -1){
                int option;
                cout<<"Cod not find, u want to add it to this product list? (no/0 yes/1): ";
                cin>>option;
                if (option == 1) addProduct();
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
        void addProduct(){
            string SearchCode = getCode();
            newProduct.ProductCode = SearchCode;
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
                cout<<"Cod: " <<SingleProduct[i].ProductCode <<endl
                    <<"Name: " <<SingleProduct[i].ProductName <<endl
                    <<"Quantity: " <<SingleProduct[i].ProductQuantity <<endl
                    <<"Price: "  <<SingleProduct[i].ProductPrice <<endl <<endl;
        }
        //sort the list of items befor print
        void sort(){
            Products tmp;
            for (int i=0; i<SingleProduct.size()-1; i++)
                for (int j=i+1; j<SingleProduct.size(); j++)
                    if(SingleProduct[i].ProductCode > SingleProduct[j].ProductCode){
                        tmp = SingleProduct[i];
                        SingleProduct[i] = SingleProduct[j];
                        SingleProduct[j] = tmp;
                    }
        }
        //delete item from the list of product
        void deleteProduct(){
            int position = searchProduct();
            if (position == -1) cout<<"Cod not find." <<endl;
            else{
                for (int i=position; i<SingleProduct.size(); i++)
                    SingleProduct.erase(SingleProduct.begin() + position);
                cout<<"Code deleted successfully." <<endl;
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
            <<" - 3 Add new cod to the list." <<endl
            <<" - 4 To delete from the list." <<endl
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
                newShop.addProduct();
            break;
            case 4:
                newShop.deleteProduct();
            break;
            default:
                cout<<"Retry..." <<endl;
            break;
        }
    } while (option != 0);
    return 0;
}