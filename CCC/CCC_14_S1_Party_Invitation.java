import java.io.*;
import java.util.*;

public class CCC_14_S1_Party_Invitation {
    public static void main(String[] args) {
        int K, m, r;
        ArrayList<Integer> ppl = new ArrayList<Integer>();

        Scanner in = new Scanner(System.in);

        K = in.nextInt();
        m = in.nextInt();

        for (int i = 1; i <= K; i++) {
            ppl.add(i);
        }

        for (int i = 0; i < m; i++) {
            r = in.nextInt();

            for (int j = 0; j < ppl.size(); j += r) {
                ppl.remove(j);
                j -= r - 1;
            }
        }

        for (int i : ppl) {
            System.out.println(i);
        }
    }
}
