/**
 * iven a string and a non-empty word string, return a string made of each char
 * just before and just after every appearance of the word in the string. Ignore
 * cases where there is no char before or after the word, and a char may be
 * included twice if it is between two words.
 */

public class WordEnds {
    public String wordEnds(String str, String word) {
        int sl, wl;
        String fin = "";

        sl = str.length();
        wl = word.length();

        for (int i = 0; i < sl - wl + 1; i++) {
            if (str.equals(word))
                break;
            else if (i == 0 && str.substring(i, i + wl).equals(word))
                fin += String.valueOf(str.charAt(i + wl));
            else if (i == sl - wl && str.substring(i, i + wl).equals(word))
                fin += String.valueOf(str.charAt(i - 1));
            else if (str.substring(i, i + wl).equals(word)) {
                fin += String.valueOf(str.charAt(i - 1));
                fin += String.valueOf(str.charAt(i + wl));
            }
        }

        return fin;
    }
}
