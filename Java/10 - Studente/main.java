class Main{
    public static void main(String[]args){
        // crea il Corso di Laurea
        Classe cl=new Classe("Informatica");
        // crea studente1
        Studente s1=new Studente("M001",cl);
        // aggiunge lo studente nella lista del Corso di Laurea
        cl.addStudente(s1);
        // crea studente2
        Studente s2=new Studente("M002",cl);
        // aggiunge lo studente nella lista del Corso di Laurea
        cl.addStudente(s2);
        // stampaidati del Corso di Laurea
        System.out.print("facolta'"+cl.getDenominazione()+"\n");
        System.out.println(cl.getListaStudenti());
        // stampaidati dello studente1
        System.out.println("Studente");
        System.out.println(s1.matricola+""+s1.GetStudenteClasse().getDenominazione());
    }
}