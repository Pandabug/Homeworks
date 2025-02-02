public class Cerchio {
    float raggio;

    Cerchio(float number){
        this.raggio = number;
    }

    public float getRaggio(){
        return this.raggio;
    }
    
    public float setRaggio(float c){
        return this.raggio = c;
    }
    
    public float calcArea() {
        return (float) 3.14 * this.raggio * this.raggio;
    }
}