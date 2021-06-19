import java.io.*;
import java.util.*;

public class A_Plus_B_Hard {
    static int[] plus(int liA[], int liB[], int liSum[]) {
        for (int i = liA.length - 1; i > 0; i--) {
            liSum[i] += liA[i] + liB[i];

            if (liSum[i] >= 10) {
                liSum[i-1] += 1;
                liSum[i] -= 10;
            }
        }

        return liSum;
    }

    static int[] minus(int liA[], int liB[], int liSum[]) {
        for (int i = liA.length - 1; i > 0; i--) {
            liSum[i] += liA[i] - liB[i];

            if (liSum[i] <= -1) {
                liSum[i-1] -= 1;
                liSum[i] += 10;
            }
        }

        return liSum;
    }

    static Boolean compare(int liA[], int liB[]) {
        for (int i = 0; i < liA.length; i++) {
            if (liA[i] != 0 || liB[i] != 0)
                if (liA[i] > liB[i])
                    return false;
                else if (liA[i] < liB[i])
                    return true;
        }

        return true;
    }

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());

        for (int f = 0; f < N; f++) {
            String list_A, list_B;

            Boolean flag = false;
            boolean compA = false;
            boolean compB = false;
            boolean putneg = false;

            String input[] = new String[2];
            int li_A[] = new int[100001];
            int li_B[] = new int[100001];
            int c[] = new int[100001];

            input = br.readLine().split(" ");

            list_A = input[0];
            list_B = input[1];

            if (list_A.charAt(0) == '-' && list_B.charAt(0) == '-') {
                putneg = true;
                list_A = list_A.replace("-", "");
                list_B = list_B.replace("-", "");
            } else if (list_A.charAt(0) == '-') {
                compA = true;
                list_A = list_A.replace("-", "");
            } else if (list_B.charAt(0) == '-') {
                compB = true;
                list_B = list_B.replace("-", "");
            }

            list_A = String.format("%100001s", list_A);
            list_B = String.format("%100001s", list_B);

            for (int i = 0; i < list_A.length(); i++) {
                if (list_A.charAt(i) != ' ')
                    li_A[i] = Character.getNumericValue(list_A.charAt(i));
                if (list_B.charAt(i) != ' ')
                    li_B[i] = Character.getNumericValue(list_B.charAt(i));
            }

            if (compA) {
                if (compare(li_A, li_B)) {
                    if (Arrays.equals(li_A, li_B))
                        System.out.println(0);
                    else {
                        for (int i : minus(li_B, li_A, c)) {
                            if (flag)
                                System.out.print(i);
                            else if (i != 0) {
                                flag = true;
                                System.out.print(i);
                            }
                        }

                        flag = false;
                        System.out.println();
                    }

                } else if (!compare(li_A, li_B)) {
                    if (Arrays.equals(li_A, li_B))
                        System.out.println(0);
                    else {
                        System.out.print("-");
                        for (int i : minus(li_A, li_B, c)) {
                            if (flag)
                                System.out.print(i);
                            else if (i != 0) {
                                flag = true;
                                System.out.print(i);
                            }
                        }

                        flag = false;
                        System.out.println();
                    }
                }
            }

            else if (compB) {
                if (compare(li_A, li_B)) {
                    if (Arrays.equals(li_A, li_B))
                        System.out.println(0);
                    else {
                        System.out.print("-");

                        for (int i : minus(li_B, li_A, c)) {
                            if (flag)
                                System.out.print(i);
                            else if (i != 0) {
                                flag = true;
                                System.out.print(i);
                            }
                        }

                        flag = false;
                        System.out.println();
                    }

                } else if (!compare(li_A, li_B)) {
                    if (Arrays.equals(li_A, li_B))
                        System.out.println(0);
                    else {
                        for (int i : minus(li_A, li_B, c)) {
                            if (flag)
                                System.out.print(i);
                            else if (i != 0) {
                                flag = true;
                                System.out.print(i);
                            }
                        }

                        flag = false;
                        System.out.println();
                    }
                }
            }

            else if (putneg) {
                System.out.print("-");

                for (int i : plus(li_A, li_B, c)) {
                    if (flag)
                        System.out.print(i);
                    else if (i != 0) {
                        flag = true;
                        System.out.print(i);
                    }
                }

                flag = false;
                System.out.println();
            }

            else if (!putneg) {
                boolean detectNum = false;

                for (int i : plus(li_A, li_B, c)) {
                    if (i != 0)
                        detectNum = true;

                    if (flag)
                        System.out.print(i);
                    else if (i != 0) {
                        flag = true;
                        System.out.print(i);
                    }
                }

                if (!detectNum)
                    System.out.print(0);

                System.out.println();
                flag = false;
            }
        }
    }
}
