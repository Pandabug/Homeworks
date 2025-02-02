public class Alloggio {
    int codice;
    int numPersone;
    double metriQuadri;

    public Alloggio(int codice, int numPersone, double metriQuadri) {
        this.codice = codice;
        this.numPersone = numPersone;
        this.metriQuadri = metriQuadri;
    }

    public int getNumPersone() {
        return numPersone;
    }
    public double getMetriQuadri() {
        return metriQuadri;
    }
    public int getCodice() {
        return codice;
    }
    public double costoAcqua(double q) {
        return q* numPersone;
    }
    public double valore(double v) {
        return v* metriQuadri;
    }
    public double densita() {
        return metriQuadri / numPersone;
    }
}
