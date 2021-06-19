/**
 * A Caesar cipher is a rudimentary encoding scheme in which each letter is
 * replaced by the letter occurring a given number of places after it in the
 * alphabet. (Imagine that the letters are listed in a circle so that A
 * immediately follows Z.) The given number is referred to as the shift because,
 * in effect, a Caesar cipher shifts all the letters of the alphabet that many
 * positions. For example, a shift of 2 would encode an 'A' as a 'C', a 'B' as a
 * 'D', ..., an 'X' as a 'Z', a 'Y' as an 'A', and 'Z' as a 'B'. The notion of a
 * negative shift makes sense too. Develop a method that accepts as input a
 * shift value and a message. The shift value will be no less than -25 and no
 * greater than 25. Any character that occurs in the message and that is not an
 * upper case letter should be encoded as itself.
 */

public class caesarCipher {
    public String CaesarCipher(int shift, String message) {
        String fin = "";

        for (int i = 0; i < message.length(); i++) {
            if (message.charAt(i) >= 'A' && message.charAt(i) <= 'Z')
                if (shift > 0)
                    fin += (char) (((int) message.charAt(i) + shift + 65) % 26 + 65);
                else
                    fin += (char) (((int) message.charAt(i) + (26 + shift) + 65) % 26 + 65);
            else
                fin += message.charAt(i);
        }

        return fin;
    }
}
