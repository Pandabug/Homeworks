import java.util.Scanner;

class Main{
    public static void main(String[] args) {
        final double val1 = 2000.0, val2 = 700.0, val3 = 1000.0, costo = 15.5;
        int i, c, nump;
        double mq, mqg, mqp;
        Alloggio a1;
        Villa v1;
        Scanner num = new Scanner(System.in);
        String s;
        
        do {
            System.out.println(" 1. gestione alloggion 2. gestione villan O.escininserisci un numero");
            i = num.nextInt();
            switch (i) {
                case 1:
                    System.out.println("inserire codice, numero di persone e mq dell'alloggio ");
                    c = num.nextInt();
                    nump = num.nextInt();
                    mq = num.nextDouble();
                    a1 = new Alloggio(c, nump, mq);

                    s="";
                    s = s + "Codice: " + a1.getCodice() + "\tNumero persone: " + a1.getNumPersone() + "\tMetri quadri: " + a1.getMetriQuadri();
                    s = s + "\nCosto totale acqua= " + a1.costoAcqua(costo) + "\nDensità in alloggio= " + a1.densita() + "\nValore= " +a1.valore(val1);
                    System.out.println(s);
                break;

                case 2:
                    System.out.println("inserire codice, numero di persone, mq della vlla, mq giardino e mq piscona ");
                    c = num.nextInt();
                    nump = num.nextInt();
                    mq = num.nextDouble();
                    mqg = num.nextDouble();
                    mqp = num.nextDouble();
                    v1 = new Villa(c, nump, mq, mqg, mqp);
                    
                    s="";
                    s = s + "Codice: "+ v1.getCodice() + "\tNumero persone: " + v1.getNumPersone() + "\tMetri quadri: "+ v1.getMetriQuadri() + "\tGiardino: " + v1.getGiardino() + "\tPiscina: " + v1.getPiscina();
                    s = s + "\nCosto totale acqua= " + v1.costoAcqua(costo) + "\nDensità in villa= " + v1.densita() + "\nValore= " + v1.valore(val1, val2, val3);
                    System.out.println(s);
                break;
            } 
        } while (i!=0);
    }
}