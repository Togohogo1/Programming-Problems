/**
 * Given an array of ints length 3, return an array with the elements "rotated
 * left" so {1, 2, 3} yields {2, 3, 1}.
 */

public class RotateLeft3 {
    public int[] rotateLeft3(int[] nums) {
        int rotate[] = new int[3];

        for (int i = 0; i < 3; i++) {
            rotate[i] = nums[(i + 1) % 3];
        }

        return rotate;
    }
}
