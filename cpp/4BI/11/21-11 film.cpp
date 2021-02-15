#include <iostream>
#include <string>
using namespace std;

const int MAX_LIMIT = 10;
int l_max = 0;

struct film{
    string title;
    string autore;
    float cost;
    string nationality;
};
film new_film[MAX_LIMIT];

//start
void inserimento_film(){
    cout <<"Inserisci il numero di film da inserire: ";
    cin>>l_max;
    for (int i=0; i<l_max; i++){
        cout <<"Inserisci il titolo del film: ";
        cin >>new_film[i].title;    
        cout <<"Inserisci l'autore del film: ";
        cin >>new_film[i].autore;
        cout <<"Inserisci l'incasso del film: ";
        cin >>new_film[i].cost;
        cout <<"Inserisci la nazionalita del film: ";
        cin >>new_film[i].nationality;
        cout <<endl;
    }
}
//+1 film
void inserimento_new_film(){
    cout <<"Inserisci il titolo del film: ";
    cin >>new_film[l_max].title;    
    cout <<"Inserisci l'autore del film: ";
    cin >>new_film[l_max].autore;
    cout <<"Inserisci il incasso del film: ";
    cin >>new_film[l_max].cost;
    cout <<"Inserisci la nazionalita del film: ";
    cin >>new_film[l_max].nationality;
    l_max++;
    cout <<endl;
}
//stampa tutti film
void stampa(){
    for (int i=0; i<l_max; i++){
        cout <<"|" <<new_film[i].title <<"\t|" <<new_film[i].autore <<"\t|" <<new_film[i].cost <<"\t|" <<new_film[i].nationality <<endl;
    }
    cout <<endl;
}
//calcolo media dell'autore
void incasso_medio_stampa(){
    string autore_search;
    int cont = 0;
    float prezzo = 0;
    bool check = false;
    cout <<"Inserisci l'autore di cui vuoi sapere l'incasso medio dei film: ";
    cin >>autore_search;
    for (int i=0; i<l_max; i++){
        if (new_film[i].autore == autore_search){
            prezzo += new_film[i].cost;
            cont++;
            check = true;
        }
    }
    prezzo = prezzo/cont;
    if (!check){
        cout <<"Autore inserito innesistente" <<endl <<endl;
    } else {
        cout <<"Il prezzo medio di un film: " <<prezzo <<endl <<endl;
    }
}
//trova info dal titolo
void search_title(){
    string search;
    bool check = false;
    cout <<"Inserisci il titolo del film da trovare: ";
    cin >>search;
    for (int i=0; i<l_max; i++){
        if (new_film[i].title == search){
            cout <<"|" <<new_film[i].title <<"\t|" <<new_film[i].autore <<"\t|" <<new_film[i].cost <<"\t|" <<new_film[i].nationality <<endl;
            check = true;
        }
    }
    if (!check){
        cout <<"Non ci sono film con questo titolo." <<endl <<endl;
    }
}
//calcolo incasso maggiore della nazione
void film_straniero(){
    string naz;
    bool check = false;
    cout <<"Inserisci la nazione di cui vorresti sapere incasso maggiore: ";
    cin >>naz;
    int inc_maggiore = 0, pos;
    for (int i=0; i<l_max; i++){
        if (new_film[i].nationality == naz){
            if (new_film[i].cost > inc_maggiore){
                inc_maggiore = new_film[i].cost;
                pos = i;
                check = true;
            }
        }
    }
    if (!check){
        cout <<"Nazione ricercata non e presente nella lista" <<endl <<endl;
    } else {
        cout <<"Il film con incasso maggior e:\n|" <<new_film[pos].title <<"\t|" <<new_film[pos].autore <<"\t|" <<new_film[pos].cost <<"\t|" <<new_film[pos].nationality <<endl <<endl;
     }
}
//stampa i film con l'incasso maggiore di quello inserito
void incasso_plus(){
    float inc;
    bool check = false;
    cout <<"Inserisci l'incasso da trovare: ";
    cin >>inc;
    for (int i=0; i<l_max; i++){
        if (new_film[i].cost > inc){
            cout <<"|" <<new_film[i].title <<endl;
            check = true;
        }
    }
    if (!check){ 
        cout <<"Non ci sono film con incasso maggiore di quello inserito" <<endl <<endl;
    }
}
//menu scelte
void menu(){
    int choice;
    inserimento_film();
    do{
        cout <<"Menu:" <<endl
            <<"  -0 Per uscire dal programma" <<endl
            <<"  -1 Per inserire un nuovo film" <<endl
            <<"  -2 Per stampare tutti i film" <<endl
            <<"  -3 Per stampare incasso medio dell'autore x" <<endl
            <<"  -4 Dato  il titolo di un film in input stampi i dati di quel film" <<endl
            <<"  -5 Per stampare incasso maggiore di una nazione" <<endl
            <<"  -6 Per stampare la lista dei titoli di film con incasso superiore all'incasso fornito in input" <<endl
            <<"La tua scelta: ";
        cin >>choice;
        cout <<endl;
        switch(choice){
            case 0:
                cout <<"--------------------------------------" <<endl
                    <<"--HAI DECISO DI USCIRE DAL PROGRAMMA--" <<endl
                    <<"--------------------------------------" <<endl;
                break;
            case 1:
                inserimento_new_film();
                break;
            case 2:
                stampa();
                break;
            case 3:
                incasso_medio_stampa();
                break;
            case 4:
                search_title();
                break;
            case 5:
                film_straniero();
                break;
            case 6:
                incasso_plus();
                break;
            default:
                cout <<"Opzione non presente riprova" <<endl <<endl;
                break;
        }
    } while (choice != 0);
}

int main(){
    menu();
}