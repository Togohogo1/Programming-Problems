import java.io.*;
import java.util.*;

public class Oly_Catch_the_Cat {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    static StringTokenizer st;

    public static void main(String[] args) throws IOException {
        System.out.println(bfs(readInt(), readInt()));
    }

    static int bfs(int start, int end) {
        int moves = 0;
        int next_layer = 0;
        int left_in_layer = 1;

        Deque<Integer> queue = new ArrayDeque<>();
        Set<Integer> vis = new HashSet<>();

        queue.add(start);
        vis.add(start);

        while (queue.size() > 0) {
            for (int i = 0; i < queue.size(); i++) {
                int curr = queue.removeFirst();

                if (curr == end)
                    return moves;


                int[] arr = {curr, 1, -1};

                for (int j : arr) {
                    int next = curr + j;

                    if (vis.contains(next) || next < 0 || next > 100000)
                        continue;

                    vis.add(next);
                    queue.add(next);
                    next_layer++;
                }

                left_in_layer -= 1;

                if (left_in_layer == 0) {
                    left_in_layer = next_layer;
                    next_layer = 0;
                    moves++;
                }
            }
        }

        return moves;
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
