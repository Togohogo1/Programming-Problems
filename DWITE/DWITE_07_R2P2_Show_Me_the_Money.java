import java.util.*;

public class DWITE_07_R2P2_Show_Me_The_Money {
    public static void main (String args[]) {
        Scanner in = new Scanner(System.in);

        int count = 0;
        String balance = "";
        boolean flag = false;

        for (int i = 0; i < 5; i++) {
            balance = in.nextLine();

            for (int j = 0; j < balance.length(); j++) {
                if (balance.charAt(j) == '-')
                    count--;
                else
                    count++;

                if (count < 0) {
                    flag = true;
                    break;
                }
            }

            if (flag) {
                System.out.println("OH NOES!");
                count = 0;
                flag = false;
            } else
                System.out.println(count);
        }

        in.close();
    }
}
