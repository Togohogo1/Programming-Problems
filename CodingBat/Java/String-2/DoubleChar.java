/**
 * Given a string, return a string where for every char in the original, there
 * are two chars.
 */

public class DoubleChar {
    public String doubleChar(String str) {
        String fin = "";

        for (int i = 0; i < str.length(); i++) {
            fin += str.substring(i, i + 1);
            fin += str.substring(i, i + 1);
        }

        return fin;
    }
}
