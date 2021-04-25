#include <iostream>
#include <string>
using namespace std;

struct paziente{
    string name;
    int num;
    struct paziente *next;
};

class coda{
    paziente *head;
    paziente *fine;
    int num;

    public:
        coda(){
            head = NULL;
            fine = NULL;
            num = 1;
        }
        void push(){
            paziente *p;

            p = new(paziente);
            cout<<"Input name: ";
            cin>>p->name;
            p -> num = num++;
            cout<<"Patient " <<p->name <<" number " <<p->num <<endl <<endl;
            p->next = NULL;
            
            if (head == NULL) head = fine = p;
            else{
                fine -> next = p;
                fine = p;
            }
        }
        void pop(){
            paziente *p;

            if (head == NULL) cout<<"Non ci sono pazienti in attesa" <<endl;
            else {
                p = head;
                head = p->next;
                cout<<"Prossino da visitare e " <<p->name <<" numero " <<p->num <<endl;
                
                if(head == NULL) fine = NULL;
                delete p;
            }
        }
        void print(){
            paziente *p;

            if (head == NULL) cout<<"Non ci sonot pazienti" <<endl;
            else {
                cout<< "ELENCO PAZIENTI IN ATTESSA:" <<endl;
                for (p=head; p!=NULL; p=p->next)
                    cout<<p->name <<"\t\t" <<p->num <<endl;
            }
            cout<<endl;
        }
        ~coda(){
            paziente *p;

            while (head != NULL){
                p = head;
                head = head -> next;
                delete(p);
            }
        }
};

int main(){
    coda studio;
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
                studio.push();
            break;
            case 2:
                studio.pop();
            break;
            case 3:
                studio.print();
            break;
            default:
                cout<<"Retry..." <<endl;
            break;
        }
    } while (option != 0);
}

