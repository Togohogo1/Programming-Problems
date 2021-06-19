import java.util.*;

public class COCI_07_C4P2_Veci {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        char s[] = in.nextLine().toCharArray();

        if (next_permutation(s))
            for (char i : s) {
                System.out.print(i);
            }
        else
            System.out.print(0);

        System.out.println();
        in.close();
    }

    static boolean next_permutation(char a[]) {
        if (a.length <= 1)
            return false;

        int n = a.length;
        int p = n - 2;
        int q = n - 1;

        while (p >= 0 && a[p] >= a[p + 1])
            p--;

        if (p < 0)
            return false;

        while (a[q] <= a[p])
            q--;

        char temp = a[p];
        a[p] = a[q];
        a[q] = temp;

        for (int x = p+1, y = n-1; x<y; x++, y--) {
            temp = a[x];
            a[x] = a[y];
            a[y] = temp;
        }

        return true;
    }
}
