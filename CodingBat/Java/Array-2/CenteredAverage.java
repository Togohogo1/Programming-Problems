/**
 * Return the "centered" average of an array of ints, which we'll say is the
 * mean average of the values, except ignoring the largest and smallest values
 * in the array. If there are multiple copies of the smallest value, ignore just
 * one copy, and likewise for the largest value. Use int division to produce the
 * final average. You may assume that the array is length 3 or more.
 */

public class CenteredAverage {
    public int centeredAverage(int[] nums) {
        int c = 0;
        int max = -1, min = 214748364;

        for (int i : nums) {
            max = Math.max(max, i);
            min = Math.min(min, i);
            c += i;
        }

        c -= (max + min);
        return c / (nums.length - 2);
    }
}
