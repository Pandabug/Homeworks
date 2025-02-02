import java.util.Scanner;

public class Main{
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.print("Input a number: ");
        int n = input.nextInt();

        int[] intArray = new int [10];

        for (int i=0; i<n; i++){
            intArray[i] = (int)Math.floor(Math.random() * 10);
    }

        for (int i=0; i<n; i++)
            System.out.println((i+1) + " - " + intArray[i]);
    }
}