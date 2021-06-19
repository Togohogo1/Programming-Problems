import java.util.*;

public class CCCHK_08_J2_Lucky_Number {
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        int temp = 0;

        int N = in.nextInt();
        in.nextLine();

        for (int i = 0; i < N; i++) {
            String x = in.nextLine();

            while (x.length() != 1) {
                for (int j = 0; j < x.length(); j++) {
                    temp += Character.getNumericValue(x.charAt(j));
                }

                x = Integer.toString(temp);
                temp = 0;
            }
            System.out.println(x);
        }

        in.close();
    }
}
