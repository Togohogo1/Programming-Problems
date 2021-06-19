/**
 * Return the number of even ints in the given array. Note: the % "mod" operator
 * computes the remainder, e.g. 5 % 2 is 1.
 */

public class CountEvens {
    public int countEvens(int[] nums) {
        int c = 0;

        for (int i : nums) {
            if (i % 2 == 0)
                c++;
        }

        return c;
    }
}
