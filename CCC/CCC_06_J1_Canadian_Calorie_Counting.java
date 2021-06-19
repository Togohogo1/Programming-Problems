import java.io.*;
import java.util.*;

public class CCC_06_J1_Canadian_Calorie_Counting {
    public static void main(String[] args) {
        int a, b, c, d;
        int[] burg = {461, 431, 420, 0}, side = {100, 57, 70, 0}, drink = {130, 160, 118, 0}, dess = {167, 266, 75, 0};

        Scanner in = new Scanner(System.in);

        a = in.nextInt() - 1;
        b = in.nextInt() - 1;
        c = in.nextInt() - 1;
        d = in.nextInt() - 1;

        System.out.println("Your total Calorie count is " + (burg[a] + side[b] + drink[c] + dess[d]) + ".");
    }
}
