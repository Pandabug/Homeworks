public class Vettori {
    int v[] = new int[100];
    public void inserimento(int pos, int val){
        v[pos] = val;
    }
    public int valore(int pos){
        return v[pos];
    }
    public void elimina(int pos, int max){
        for(int i=pos; i<max; i++){
            v[i] = v[i+1];
        }
    }
    public double media(int maxCont){
        double media = 0;
        for(int i=0; i<maxCont; i++){
            media = media + v[i];
        }
        return media/maxCont;
    }
    public void dev_max_media(int maxCont){
        double media = media(maxCont);
        double max = 0;
        int pos = 0;
        for(int i=0;i<maxCont; i++){
            double deviazione = v[i]-media;
            if(max<deviazione){
                max = deviazione;
                pos = i;
            }
        }
        System.out.println("\nMedia prezzo: "+media);
        System.out.println("\nValore con deviazione massima: "+max+" in pos: "+pos);
    }
}