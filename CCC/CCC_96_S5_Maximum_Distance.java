import java.io.*;
import java.util.*;

public class BitPatterns {
    static int x, n, k;
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        x = in.nextInt();
        int[] comb = new int[30];

        for (int i = 0; i < x; i++) {
            n = in.nextInt();
            k = in.nextInt();

            System.out.println("The bit patterns are");
            bitPatterns(k, n, "");

            if (i != x - 1)
                System.out.println();
        }
    }

    public static void bitPatterns(int cnt, int len, String ans) {
        if (len == 0) {
            if (cnt == 0)
                System.out.println(ans);

            return;
        }

        if (cnt != 0)
            bitPatterns(cnt-1, len-1, ans+"1");

        bitPatterns(cnt, len-1, ans+"0");
    }
}
