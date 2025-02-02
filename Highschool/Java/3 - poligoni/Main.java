import java.util.Scanner;

public class Main{
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        Cerchio c;
        Quadrato q;
        Triangolo t;
        Trapezio trap;

        System.out.print("Input a number: ");
        float number = input.nextFloat();

        q = new Quadrato(number);
        float diagonale = q.calcDiagonale(number);
        float raggio = diagonale / 2;
        c = new Cerchio(raggio);

        System.out.print("Input lato 1: ");
        float rage1 = input.nextFloat();
        System.out.print("Input lato 2: ");
        float rage2 = input.nextFloat();
        System.out.print("Input lato 3: ");
        float rage3 = input.nextFloat();
        t = new Triangolo(rage1, rage2, rage3);

        System.out.print("Input base maggiore: ");
        float b1 = input.nextFloat();
        System.out.print("Input base minore: ");
        float b2 = input.nextFloat();
        System.out.print("Input lato 1: ");
        float l1 = input.nextFloat();
        System.out.print("Input lato 2: ");
        float l2 = input.nextFloat();
        System.out.print("Input altezza: ");
        float h = input.nextFloat();
        trap = new Trapezio(b1, b2, l1, l2, h);

        System.out.println("Area del cerchio circoscritto = " + c.calcArea());
        System.out.println("Area del quadrato = " + q.calcArea());
        System.out.println("Diagonale del quadrato = " + q.diagonale());
        System.out.println("Perimetro del triangolo = " + t.perimetro());
    }
}