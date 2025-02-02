#include <iostream>
#include <string>
using namespace std;

struct nome{
    string name;
    int points;
    struct nome *next;
};

class List{
    nome *first;
    public:
        List(){
            //start input
            first = new(nome);
            first -> name = "\0";
            first -> points =1000;
            
            //end input
            first -> next = new(nome);
            first -> next ->  name= "\0";
            first -> next ->  points= 0;
            first -> next ->  next= NULL;

        }
        void input(){
            nome *name1, *name2, *name3;

            name1 = new(nome);
            cout<<"Input name: ";
            cin>>name1->name;
            cout<<"Input points: ";
            cin>>name1->points;
            name1 -> next = NULL;

            name2 = first;
            for (name3=first; name3->points>name1->points; name2=name3,name3=name2->next);
            name2 -> next = name1;
            name1 ->next = name3;

        }
        void deleteName(){
            nome *name1, *name2;
            string nameSearch;

            cout<<"Input name to search: ";
            cin>>nameSearch;

            name1 = first;
            
            for (name2 = first; name2->name!=nameSearch && name2->next!=NULL; name1=name2, name2=name2->next);
            if (name2->name == nameSearch){
                name1 -> next = name2 -> next;
                delete name2;
            }
            else cout<<"Name not find." <<endl;
        }
        void print(){
            nome *position;
            
            if (first->next->next == NULL) cout<<"No one are in class." <<endl;
            else for (position=first->next; position->next!=NULL; position=position->next)
                    cout<<"Name: " <<position->name <<endl
                        <<"Points: " <<position->points <<endl <<endl;
        }
        ~List(){
            nome *position;

            while (first != NULL){
                position = first;
                first = first->next;
                delete(position);
            }
        }
};

int main(){
    List newList;

    int option;
    do{
        cout<<endl <<"Menu:" <<endl
            <<" - 0 EXIT" <<endl
            <<" - 1 Input" <<endl
            <<" - 2 Delete" <<endl
            <<" - 3 Print" <<endl
            <<"Option: ";
        cin>>option;
        cout<<endl;
        switch (option){
            case 0:
                cout<<"EXIT" <<endl;
            break;
            case 1:
                newList.input();
            break;
            case 2:
                newList.deleteName();
            break;
            case 3:
                newList.print();
            break;
            default:
                cout<<"Retry..." <<endl;
            break;
        }
    } while (option != 0);
}