import java.io.*;
import java.util.*;

public class temp {
    static int right(int code[], int orig[], int idx) {
        while (code[idx] - orig[idx-1] < 0) {
            code[idx] += 26;
        }

        return code[idx] - orig[idx-1];
    }

    static int left(int code[], int orig[], int idx) {
        while (code[idx] - orig[idx+1] < 0) {
            code[idx] += 26;
        }

        return code[idx] - orig[idx+1];
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str, fin = "";

        int T = Integer.parseInt(br.readLine());

        for (int i = 0; i < T; i++) {
            str = br.readLine();

            int code[] = new int[str.length()];

            for (int j = 0; j < str.length(); j++) {
                code[j] = (int) str.charAt(j) - 65;
            }

            int orig[] = new int[str.length()];

            if (str.length() % 2 == 0) {
                orig[1] = code[0];
                orig[str.length()-2] = code[str.length()-1];

                for (int j = 2; j < str.length() - 1; j += 2) {
                    orig[j+1] = right(code, orig, j);
                }

                for (int j = str.length() - 3; j >= 0; j -= 2) {
                    orig[j-1] = left(code, orig, j);
                }

                for (int j = 0; j < str.length(); j++) {
                    fin += (char)(orig[j]+65);
                }

                System.out.println("Case #" + (i+1) + ": " + fin);
                fin = "";

            } else
                System.out.println("Case #" + (i+1) + ": AMBIGUOUS");
        }
    }
}
