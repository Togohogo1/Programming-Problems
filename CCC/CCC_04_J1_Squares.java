import java.util.*;

public class CCC_04_J1_Squares {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int answer = 0;
        int squarenum;

        squarenum = in.nextInt();

        for (int i = squarenum; i > 0; i--) {
            if (Math.sqrt(i) % 1 == 0) {
                answer = (int) Math.sqrt(i);
                break;
            }
        }

        System.out.println("The largest square has side length " + answer + ".");
        in.close();
    }
}
