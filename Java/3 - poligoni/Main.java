import java.util.Scanner;

public class Main{
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        Cerchio c;
        Quadrato q;

        System.out.print("Input a number: ");
        float number = input.nextFloat();

        q = new Quadrato(number);
        float diagonale = q.calcDiagonale(number);
        float raggio = diagonale / 2;
        c = new Cerchio(raggio);

        System.out.println("Area del cerchio circoscritto = " + c.calcArea());
        System.out.println("Area del quadrato = " + q.calcArea());

    }
}