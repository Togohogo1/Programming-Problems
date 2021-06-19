/**
 * Given a string, return a new string made of 3 copies of the last 2 chars of
 * the original string. The string length will be at least 2.
 */

public class ExtraEnd {
    public String extraEnd(String str) {
        String lastTwo = str.substring(str.length() - 2);
        return lastTwo + lastTwo + lastTwo;
    }
}
