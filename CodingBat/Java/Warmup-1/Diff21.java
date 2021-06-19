/**
 * Given an int n, return the absolute difference between n and 21, except
 * return double the absolute difference if n is over 21.
 */

public class Diff21 {
    public int diff21(int n) {
        if (n <= 21)
            return Math.abs(21 - n);

        return 2 * Math.abs(21 - n);
    }
}
