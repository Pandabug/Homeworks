#include <iostream>
#include <string>
using namespace std;

struct vecture{
    string target;
    int cil;
    struct vecture *next;
};

class pila{
    vecture *head;

    public:
        pila(){
            head = NULL;
        }
        void push(){
            vecture *p;

            p = new(vecture);
            cout<<"Number target: ";
            cin>>p->target;
            cout<<"Cilindrata: ";
            cin>>p->cil;
            p -> next = head;
            head = p;
        }
        void pop(){
            vecture *p;

            if (head == NULL) cout<<"Non ci sono autovetture disponibili attendere." <<endl;
            else{
                p = head;
                head = p -> next;
                cout<<"La vettura assegnata ha targa: " <<p -> target <<", e cilindrata: " <<p -> cil <<endl;
                delete p;
            }
        }
        void print(){
            vecture *p;
            
            if (head == NULL) cout<<"Non ci sono autovetture disponibili." <<endl;
            else{
                cout<<"ELENCO AUTOVETTTURE DISPONIBILI" <<endl;
                for (p=head; p!=NULL; p=p->next) 
                    cout<<p->target <<"\t\t" <<p->cil <<endl;
            }
        }  
        ~pila(){
            vecture *p;

            while (head != NULL){
                p = head;
                head = head -> next;
                delete(p);
            }
        }
};

int main(){
    pila garage;
    int option;

    do {
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
                garage.push();
            break;
            case 2:
                garage.pop();
            break;
            case 3:
                garage.print();
            break;
            default:
                cout<<"Retry..." <<endl;
            break;
        }
    } while (option != 0);
}