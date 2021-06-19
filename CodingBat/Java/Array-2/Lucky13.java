/**
 * Given an array of ints, return true if the array contains no 1's and no 3's.
 */

public class Lucky13 {
    public boolean lucky13(int[] nums) {
        for (int i : nums) {
            if (i == 1 || i == 3)
                return false;
        }

        return true;
    }
}
