class Main{
    public static void main(String[] args) {
        Contatore c1 = new Contatore(10);
        ContatoreDoppio c2 = new ContatoreDoppio(10);

        System.out.println("Valore iniziale contatori: ");
        System.out.println("- singolo - " + c1.getValore());
        System.out.println("- doppio - " + c2.getValore());

        c1.incrementa();
        c2.incrementa();

        System.out.println("Valore finale contatori: ");
        System.out.println("- singolo - " + c1.getValore());
        System.out.println("- doppio - " + c2.getValore());
    }
}