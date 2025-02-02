public class Contatore {
    float num;

    Contatore(float number) {
        this.num = number;
    }

    public float getValore(){
        return num;
    }
    
    public void incrementa(){
        this.num++;
    }
}
