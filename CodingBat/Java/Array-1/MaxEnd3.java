/**
 * Given an array of ints length 3, figure out which is larger, the first or
 * last element in the array, and set all the other elements to be that value.
 * Return the changed array.
 */

public class MaxEnd3 {
    public int[] maxEnd3(int[] nums) {
        int arr[] = new int[3];

        for (int i = 0; i < 3; i++) {
            arr[i] = Math.max(nums[0], nums[2]);
        }

        return arr;
    }
}
