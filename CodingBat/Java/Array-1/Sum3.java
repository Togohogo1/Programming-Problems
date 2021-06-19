/**
 * Given an array of ints length 3, return the sum of all the elements.
 */

public class Sum3 {
    public int sum3(int[] nums) {
        int s = 0;

        for (int i : nums) {
            s += i;
        }

        return s;
    }
}
