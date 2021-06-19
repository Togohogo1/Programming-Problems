/**
 * Return the sum of the numbers in the array, returning 0 for an empty array.
 * Except the number 13 is very unlucky, so it does not count and numbers that
 * come immediately after a 13 also do not count.
 */

public class Sum13 {
    public int sum13(int[] nums) {
        int c = 0;

        if (nums.length == 0)
            return 0;

        for (int i = 0; i < nums.length - 1; i++) {
            if (nums[i] != 13)
                c += nums[i];
            else if (nums[i] == 13 && nums[i + 1] != 13)
                c -= nums[i + 1];
        }

        if (nums[nums.length - 1] != 13)
            c += nums[nums.length - 1];

        return c;
    }
}
