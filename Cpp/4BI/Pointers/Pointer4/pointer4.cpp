#include <iostream>
#include <string>
using namespace std;

struct list{
    int numberList;
    string name;
    string todo;
    list *next;
};

class tail{
    list *head;
    list *end;
    int numberList;

    public:
        tail(){
            head = NULL;
            end = NULL;
            numberList = 1;
        }
        void push(){
            list *p;

            p = new(list);
            cout<<"Input code: ";
            cin>>p->numberList;
            cout<<"Input name: ";
            cin>>p->name;
            cout<<"Input description: ";
            cin>>p->todo;
            p->next = NULL;

            if (head == NULL) 
                head = end = p;
            else{
                end->next = p;
                end = p;
            }
        }
        void pop(){
            list *p = NULL;
            list *pp;
            int get_name_to_delete;

            cout<<"Input name to delete form the list: ";
            cin>>get_name_to_delete;

            for(list* i=head; i!=NULL; i=i->next){
                if (i->numberList == get_name_to_delete){
                    p = i;
                    break;
                }
                pp = i;
            }

            if (p != NULL){
                if (head == NULL)
                    cout<<"There are not anything to do in the list." <<endl;
                else{
                    pp->next = p->next;
                    
                    if (p == NULL)
                        end = NULL;
                    delete p;
                }
            } else {
                cout<<"Name doesn't exist." <<endl;
            }
        }
        void print(){
            list *p;

            if (head == NULL)
                cout<<"There are not anything to do in the list." <<endl;
            else{
                cout<<"The list to do:" <<endl;
                
                for (p=head; p!=NULL; p=p->next)
                    cout<<p->numberList <<"\t\t" <<p->name <<"\t\t" <<p->todo <<endl;
            }
        }
};

int main(){
    tail office;
    int option;

    do{
        cout<<"Menu:" <<endl
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
                office.push();
            break;
            case 2:
                office.pop();
            break;
            case 3:
                office.print();
            break;
            default:
                cout<<"Retry..." <<endl;
            break;
        }
    } while (option != 0);
}