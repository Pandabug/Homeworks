public class Trapezio {
    float lato1, lato2, lato3, lato4, h;

    Trapezio (float b1, float b2, float l1, float l2, float h){
        this.lato1 = b1;
        this.lato2 = b2;
        this.lato3 = l1;
        this.lato4 = l2;
        this.h = h;
    }

    public float perimetro() {
        return lato1 + lato2 + lato3 + lato4;
    }

    public float area(){
        return ((lato1 + lato2) * h) / 2;
    }
}
