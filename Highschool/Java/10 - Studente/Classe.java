import java.util.ArrayList;

public class Classe{
    private String denominazione;
    private ArrayList <Studente> studenti = new ArrayList <Studente>();

 // costruttore
    public Classe(String denominazione){
        this.denominazione=denominazione;
    }
    
    public String getDenominazione(){
        return this.denominazione;
    }
    
    public void addStudente(Studente c){
        studenti.add(c);
    }
    
    public String getListaStudenti(){
        String s="";
        int i;

        for(i=0;i<studenti.size();i++)
            s=s+studenti.get(i).getMatricola()+"\n";
    
        return s;
    }
}