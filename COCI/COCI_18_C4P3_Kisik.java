import java.util.*;
import java.io.*;

public class COCI_18_C4P3_Kisik {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    static StringTokenizer st;

    public static void main(String[] args) throws IOException {
        int N = readInt();
        int K = readInt();

        long[][] arr = new long[N][2];
        PriorityQueue<Long> q = new PriorityQueue<Long>(Collections.reverseOrder());

        for (int i = 0; i < N; i++) {
            arr[i][1] = readLong();
            arr[i][0] = readLong();
        }

        Arrays.sort(arr, new Comparator<long[]>() {
            public int compare(long[] a, long[] b) {
                int yComp = Double.compare(a[0], b[0]);

                if (yComp == 0)
                    return Double.compare(a[1], b[1]);
                else
                    return yComp;
            }
        });

        long width = 0, temp = 0;

        for (int i = 0; i < K; i++) {
            width += arr[i][1];
            q.add(arr[i][1]);
        }

        long ans = width * arr[(int) K - 1][0];

        for (int i = K; i < N; i++) {
            temp = arr[i][0] * (width - q.peek() + arr[i][1]);
            width = width - q.peek() + arr[i][1];
            ans = Math.min(ans, temp);

            q.poll();
            q.add(arr[i][1]);
        }

        System.out.println(ans);
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
