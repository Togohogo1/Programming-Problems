import java.util.*;

public class CCC_12_J2_Sounds_Fishy {
    public static void main(String[] args) {
        int p1, p2, p3, p4;
        p1 = p2 = p3 = p4 = 0;

        Scanner in = new Scanner(System.in);

        p1 = in.nextInt();
        p2 = in.nextInt();
        p3 = in.nextInt();
        p4 = in.nextInt();

        if (p1 < p2 && p2 < p3 && p3 < p4)
            System.out.println("Fish Rising");
        else if (p1 > p2 && p2 > p3 && p3 > p4)
            System.out.println("Fish Diving");
        else if (p1 == p2 && p2 == p3 && p3 == p4)
            System.out.println("Fish At Constant Depth");
        else
            System.out.println("No Fish");

        in.close();
    }
}