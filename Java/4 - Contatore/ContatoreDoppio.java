public class ContatoreDoppio extends Contatore {
    ContatoreDoppio (float number) {
        super(number);
    }

    public void incrementa() {
        super.incrementa();
        super.incrementa();
    }
}
