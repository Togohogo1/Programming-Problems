/**
 * Given 2 int arrays, a and b, each length 3, return a new array length 2
 * containing their middle elements.
 */

public class MiddleWay {
    public int[] middleWay(int[] a, int[] b) {
        int arr[] = new int[2];

        arr[0] = a[1];
        arr[1] = b[1];

        return arr;
    }
}
