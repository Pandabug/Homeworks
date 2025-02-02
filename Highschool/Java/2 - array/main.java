import java.util.Random;
import java.util.Scanner;

public class Main{
    final static int[] array = new int [20];
    final static int maxRand = 10;

    public static void inputArray(){
        Random rand = new Random();

        for (int i=0; i<array.length; i++)
            array[i] = rand.nextInt(maxRand);
    }

    public static void search(int num){
        int cont = 0, numberToSearch;
        boolean check = false;

        for (int i=0; i<array.length; i++)
            if (array[i] == num){
                check = true;
                cont++;
            }

        if (check)
            if (cont > 1)
                System.out.println("Il numero: " + num + ", e presente " + cont + " volte");
            else
                System.out.println("Il numero: " + num + ", e presente " + cont + " volta");
        else
            System.out.println("Il numero non e presente");
    }

    public static void print(){
        for (int i=0; i<array.length; i++)
            System.out.println((i+1) + " - " + array[i]);
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        inputArray();

        System.out.print("Input a number: ");
        int number = input.nextInt();

        print();

        search(number);
    }
}