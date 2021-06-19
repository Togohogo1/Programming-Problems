import java.util.*;
import java.io.*;

public class ECOO_20_P2_Online_Shopping {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    static StringTokenizer st;

    public static void main(String[] args) throws IOException {
        for (int T = readInt(); T > 0; T--) {
            int n = readInt();
            Map<String, List<pair>> map = new HashMap();

            for (int i = 1; i <= n; i++) {
                int m = readInt();

                for (int j = 1; j <= m; j++) {
                    String item = next();
                    int p = readInt(), q = readInt();

                    if (!map.containsKey(item))
                        map.put(item, new ArrayList<pair>());

                    map.get(item).add(new pair(p, q));
                }
            }

            int k = readInt(), cost = 0;

            for (int i = 1; i <= k; i++) {
                String item = next();
                int q = readInt();

                Collections.sort(map.get(item));

                for (pair p : map.get(item)) {
                    if (p.amount <= q) {
                        cost += p.price * p.amount;
                        q -= p.amount;
                    } else {
                        cost += p.price * q;
                        break;
                    }
                }
            }

            System.out.println(cost);
        }
    }

    static class pair implements Comparable<pair> {
        int price, amount;

        pair(int p, int a) {
            price = p;
            amount = a;
        }

        public int compareTo(pair x) {
            return Integer.compare(price, x.price);
        }
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
