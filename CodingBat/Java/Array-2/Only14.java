/**
 * Given an array of ints, return true if every element is a 1 or a 4.
 */

public class Only14 {
    public boolean only14(int[] nums) {
        for (int i : nums) {
            if (i != 4 && i != 1)
                return false;
        }

        return true;
    }
}
