/**
 * Return true if the given string contains an appearance of "xyz" where the xyz
 * is not directly preceeded by a period (.). So "xxyz" counts but "x.xyz" does
 * not.
 */

public class XyzThere {
    public boolean xyzThere(String str) {
        boolean flag = false;
        str = "_" + str;

        if (str.length() > 3)
            for (int i = 0; i < str.length() - 3; i++)
                if (str.charAt(i) != '.' && str.substring(i + 1, i + 4).equals("xyz"))
                    flag = true;

        return flag;
    }
}
