public class Quadrato {
    float lato;

    Quadrato(float number){
        this.lato = number;
    }

    public float getLato() {
        return lato;
    }
    
    public float setLato(float c) {
        return this.lato = c;
    }

    public float calcDiagonale(float c) {
        return (float) Math.sqrt((c * c) + (c * c));
    }

    public float calcArea() {
        return (float) this.lato * this.lato;
    }

    public float diagonale() {
        return (float) Math.sqrt(Math.pow(this.lato, 2) * 2);
    }
}