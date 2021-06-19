/**
 * Given an array of ints length 3, return a new array with the elements in
 * reverse order, so {1, 2, 3} becomes {3, 2, 1}.
 */

public class Reverse3 {
    public int[] reverse3(int[] nums) {
        int reversed[] = new int[3];

        for (int i = 2; i >= 0; i--) {
            reversed[2 - i] = nums[i];
        }

        return reversed;
    }
}
