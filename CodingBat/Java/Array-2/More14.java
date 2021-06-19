/**
 * Given an array of ints, return true if the number of 1's is greater than the
 * number of 4's.
 */

public class More14 {
    public boolean more14(int[] nums) {
        int ones = 0;
        int fours = 0;

        for (int i : nums)
            if (i == 1)
                ones++;
            else if (i == 4)
                fours++;

        return ones > fours;
    }
}
