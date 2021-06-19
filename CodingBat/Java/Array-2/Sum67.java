/**
 * Return the sum of the numbers in the array, except ignore sections of numbers
 * starting with a 6 and extending to the next 7 (every 6 will be followed by at
 * least one 7). Return 0 for no numbers.
 */

public class Sum67 {
    public int sum67(int[] nums) {
        int c = 0;
        boolean seen = false;

        for (int i : nums) {
            if (i == 6)
                seen = true;

            if (!seen)
                c += i;

            if (i == 7)
                seen = false;
        }

        return c;
    }
}
