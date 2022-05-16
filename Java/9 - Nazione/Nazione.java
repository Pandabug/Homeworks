public class Nazione {
    String nomeN;
    String sigla;
    Capitale capitale;

    public Nazione(String nome,String sigla) {
        this.nomeN = nome;
        this.sigla = sigla;
    }

    public String getNomeN() { 
        return nomeN; 
    }

    public String getSigla() { 
        return sigla; 
    }

    public Capitale getCapitale() { 
        return capitale; 
    }

    public void setCapitale(Capitale capitale){
        this.capitale = capitale; 
    }
}