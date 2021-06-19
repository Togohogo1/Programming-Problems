import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    static StringTokenizer st;

    public static void main(String[] args) throws IOException {
        String str = readLine();
        str = str.replaceAll("[\\(\\)]", "");

        String s[] = str.split(" ");
        Stack<Integer> stack = new Stack();

        for (int i = s.length - 1; i >- 1; i--){
            if (s[i].equals("+")){
                int op1 = stack.pop();
                int op2 = stack.pop();
                stack.push(op1 + op2);
            } else{
                stack.push(Integer.parseInt(s[i]));
            }
        }

        System.out.println(stack.pop());
    }

    static String next() throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());

        return st.nextToken();
    }

    static long readLong() throws IOException {
        return Long.parseLong(next());
    }

    static int readInt() throws IOException {
        return Integer.parseInt(next());
    }

    static double readDouble() throws IOException {
        return Double.parseDouble(next());
    }

    static char readCharacter() throws IOException {
        return next().charAt(0);
    }

    static String readLine() throws IOException {
        return br.readLine().trim();
    }
}
