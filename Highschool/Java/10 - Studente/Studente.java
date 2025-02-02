public class Studente{
    String matricola;
    Classe studenteClasse;
    // costruttore con parametri
    public Studente(String matricola,Classe studenteClasse){
        this.matricola=matricola;
        this.studenteClasse=studenteClasse;
    }
    public String getMatricola(){
        return this.matricola;
    }
    public Classe GetStudenteClasse(){
        return this.studenteClasse;
    }
}