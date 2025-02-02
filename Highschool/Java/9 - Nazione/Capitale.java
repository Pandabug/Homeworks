public class Capitale {
    String nomeC;
    Nazione nazione;

    public Capitale(String nome) {
        this.nomeC = nome;
    }

    public String getNomeC() { 
        return nomeC; 
    }

    public Nazione getNazione() { 
        return nazione; 
    }

    public void setNazione(Nazione nazione) {
        this.nazione = nazione;
    }
}