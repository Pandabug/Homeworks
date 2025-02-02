class Main{
    public static void main(String[] args) {
        String nome = "Italia";
        String sigla = "ITA";
        String nomec = "Roma";
        String s="";
        Nazione n = new Nazione(nome, sigla);
        Capitale c = new Capitale(nomec);
        // crea l'associazione Nazione - Capitale
        n.setCapitale(c);
        // crea l'associazione Capitale - Nazione
        c.setNazione(n);
        // stampa i dati di Nazione
        s += "nome nazione " + n.getNomeN();
        s += "\tsigla " + n.getSigla();
        s += "\tcapitale " + n.getCapitale().getNomeC();
        System.out.println (s);
        // stampa i dati di Capitale
        s = "nome capitale " + c.getNomeC();
        s += "\tnazione " + c.getNazione().getNomeN();
        s += "\tsigla " + c.getNazione().getSigla();
        System.out.println (s);
    }
}