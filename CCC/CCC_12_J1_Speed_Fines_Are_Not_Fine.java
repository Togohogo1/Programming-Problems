import java.util.*;

public class CCC_12_J1_Speed_Fines_Are_Not_Fine {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int a, b;

        a = in.nextInt();
        b = in.nextInt();

        if (b > a)
            if (b < 20 + a)
                System.out.println("You are speeding and your fine is $100.");
            else if (b > 20 + a && b <= 30 + a)
                System.out.println("You are speeding and your fine is $270.");
            else
                System.out.println("You are speeding and your fine is $500.");
        else
            System.out.println("Congratulations, you are within the speed limit!");


        in.close();
    }
}
