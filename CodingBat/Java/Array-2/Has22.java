/**
 * Given an array of ints, return true if the array contains a 2 next to a 2
 * somewhere.
 */

public class Has22 {
    public boolean has22(int[] nums) {
        boolean next = false;

        if (nums.length <= 1)
            return false;
        else if (nums[0] == 2 && nums[1] == 2)
            return true;

        for (int i = 1; i < nums.length - 1; i++) {
            if (nums[i] == 2 && (nums[i - 1] == 2 || nums[i + 1] == 2))
                next = true;
        }

        return next;
    }
}
