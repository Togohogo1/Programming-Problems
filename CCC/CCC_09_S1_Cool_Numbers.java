import java.util.*;

public class CCC_09_S1_Cool_Numbers {
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        int queryA = 0, queryB = 0;

        int a = in.nextInt();
        int b = in.nextInt();

        for (int i = 0; i < 22; i++)
            if (a > Math.pow(i, 6))
                queryA = i;

        for (int i = 0; i < 22; i++)
            if (b > Math.pow(i, 6))
                queryB = i;
            else if (a == Math.pow(i, 6))
                queryB += 1;

        System.out.println(queryB - queryA);

        in.close();
    }
}
