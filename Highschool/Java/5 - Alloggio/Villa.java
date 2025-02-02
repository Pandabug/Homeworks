public class Villa extends Alloggio{
    private double giardino, piscina;

    public Villa (int codice, int numPersone, double metriQuadri, double giardino, double piscina){
        super (codice, numPersone, metriQuadri);
        this.giardino = giardino;
        this.piscina = piscina;
    }
    public double getGiardino(){
        return giardino;
    }
    public double getPiscina(){
        return piscina;
    }
    public double valore (double v1, double v2, double v3){
        double r1;

        r1 = super.valore(v1) + v2 * giardino + v3* piscina;
        return r1;
    }

    @Override
    public double densita(){
        return ((getMetriQuadri() + giardino) / getNumPersone());
    }
    
}
