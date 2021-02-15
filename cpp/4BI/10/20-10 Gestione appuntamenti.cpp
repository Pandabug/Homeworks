//COPIATO DA LUCA
#include <iostream>
#include <string>
using namespace std;

const int rows = 24;
const int cols = 6;
string APP[rows][cols];

string appointment(string surname, int day, int hour){
    if(hour<0 || hour>=24){
        return "Ora inserita non valida.";
    }
    if(day<0 || day>6){
        return "Giorno inserito non valido.";
    }
    if(APP[hour][day] == ""){
        APP[hour][day] = surname;
        return "Appuntamento registrato correttamente.";
    } else{
        return "Appuntamento non disponibile, selezionare un'altro orario.";
    }
}

void dailyprint(int day){
    bool noappointement = true;
    for(int i=0; i<rows; i++){
        if(APP[i][day] != ""){
            cout<<"Appuntamento ore " <<i <<": " <<APP[i][day] <<endl;
            noappointement = false;
        }
    }
    if(noappointement) cout<<"Non ci sono appuntamenti registrati per il giorno selezionato." <<endl;
}

void surnameappointment(string surname){
    bool found = false;
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(APP[i][j] == surname){
                string dayconverted;
                switch(j){
                    case 0:
                        dayconverted = "Lunedi";
                        break;
                    case 1:
                        dayconverted = "Martedi";
                        break;
                    case 2:
                        dayconverted = "Mercoledi";
                        break;
                    case 3:
                        dayconverted = "Giovedi";
                        break;
                    case 4:
                        dayconverted = "Venerdi";
                        break;
                    case 5:
                        dayconverted = "Sabato";
                        break;
                    case 6:
                        dayconverted = "Domenica";
                        break;
                }
                cout<<"Il paziente " <<APP[i][j] <<" ha un appuntamento registrato " <<dayconverted <<" alle " <<i <<"." <<endl;
                found = true;
                break;
            }
        }
        if(found) break;
    }
    if(!found) cout<<"Il paziente non ha registrato appuntamenti." <<endl;
}

void menu(){
    int option = -1;
    while(option!=0){
        cout<<"Selezionare opzione desiderata: " <<endl <<"  1: Registra nuovo appuntamento." <<endl <<"  2: Visualizza appuntamenti del giorno x." <<endl <<"  3: Visualizza appuntamento per cognome." <<endl <<"  0: Termina il programma." <<endl;
        cin>>option;
        switch(option){
            case 0:
                break;
            case 1:
                {
                    int day, hour;
                    string surname;
                    cout<<"Inserire il giorno: ";
                    cin>>day;
                    cout<<"Inserire l'ora: ";
                    cin>>hour;
                    cout<<"Inserire il proprio cognome: ";
                    cin>>surname;
                    string output = appointment(surname, day, hour);
                    cout<<output <<endl <<endl;
                    break;
                }
            case 2:
                {
                    int day;
                    cout<<"Inserire il giorno: ";
                    cin>>day;
                    dailyprint(day);
                    cout<<endl;
                    break;
                }
            case 3:
                {
                    string surname;
                    cout<<"Inserire il cognome: ";
                    cin>>surname;
                    surnameappointment(surname);
                    cout<<endl;
                }
        }
    }
}

int main(){
    menu();
    return 0;
}