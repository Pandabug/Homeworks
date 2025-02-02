public class Triangolo {
    float lato1;
    float lato2;
    float lato3;

    Triangolo(float rage1, float rage2, float rage3){
        this.lato1 = rage1;
        this.lato2 = rage2;
        this.lato3 = rage3;
    }
    
    public float perimetro(){
        return (float) this.lato1 + this.lato2 + this.lato3;
    }
}
