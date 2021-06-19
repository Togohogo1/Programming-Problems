/**
 * Given an array length 1 or more of ints, return the difference between the
 * largest and smallest values in the array. Note: the built-in Math.min(v1, v2)
 * and Math.max(v1, v2) methods return the smaller or larger of two values.
 */

public class BigDiff {
    public int bigDiff(int[] nums) {
        int max = -1, min = 2147483647;

        for (int i : nums) {
            max = Math.max(max, i);
            min = Math.min(min, i);
        }

        return max - min;
    }
}
