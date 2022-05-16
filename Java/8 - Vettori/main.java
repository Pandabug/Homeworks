import java.util.Scanner;

class Main {
public static void main(String[] args){
    Scanner scan = new Scanner(System.in);
    Vettori codice = new Vettori();
    Vettori prezzo = new Vettori();
    Vettori ore = new Vettori();
    int scelta, maxCont = 0;
    do{
        System.out.println("\nInserire valore per scegliere opzione\n1) Inserimento cellulare\n2) Stampa lista cellulari\n3) Stampa media Prezzi\n4) Stampa media Ore\n5) Stampa posizione relativa cellulare prezzo massimo\n6) Eliminazione cellulare in posizione data da input\n7)Deviazione massima dalla media\n0) Esci dal programma");
        scelta = scan.nextInt();
        switch (scelta){
            case 0: System.out.println("\n---Uscendo dal programma---");
            case 1: {
                int c, p, o;
                System.out.println("\nInserire codice cellulare "+(maxCont+1));
                c = scan.nextInt();
                codice.inserimento(maxCont, c);
                System.out.println("Inserire prezzo cellulare "+(maxCont+1));
                p = scan.nextInt();
                prezzo.inserimento(maxCont, p);
                System.out.println("Inserire ore cellulare "+(maxCont+1));
                o = scan.nextInt();
                ore.inserimento(maxCont, o);
                maxCont++;
            }
            case 2: {
                for(int i=0; i<maxCont; i++){
                    System.out.println("\nCellulare "+(i)+":");
                    System.out.println("\tCodice: "+codice.valore(i));
                    System.out.println("\tPrezzo: "+prezzo.valore(i));
                    System.out.println("\tOre autonomia: "+ore.valore(i));
                }
            }
            case 3: {
                System.out.println("\nMedia prezzi: "+prezzo.media(maxCont));
            }
            case 4: {
                System.out.println("\nMedia ore: "+ore.media(maxCont));
            }
            case 5: {
                int max = prezzo.valore(0), pos = 0;
                for(int i=0; i<maxCont; i++){
                    if(max<prezzo.valore(i)){
                        max = prezzo.valore(i);
                        pos = i;
                    }
                }
                System.out.println("\nCellulare con prezzo massimo in pos: "+pos+"\nCodice: "+codice.valore(pos)+"\nPrezzo: "+prezzo.valore(pos)+"\nOre autonomia: "+ore.valore(pos));
            }
            case 6: {
                int pos, tmp;
                System.out.println("\nInserire posizione da eliminare");
                pos = scan.nextInt();
                if(pos>0 && pos<=maxCont){
                    codice.elimina(pos, maxCont);
                    prezzo.elimina(pos, maxCont);
                    ore.elimina(pos, maxCont);
                    maxCont--;
                    System.out.println("\nEliminazione effettuata");
                }   
                else
                    System.out.println("\nInserire posizione valida");
            }
            case 7: {
                prezzo.dev_max_media(maxCont);
            }
        }
    }while(scelta != 0);
}
}