import java.util.*;

public class CCC_11_J1_Which_Alien {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int eyes, ants;

        ants = in.nextInt();
        eyes = in.nextInt();

        if (ants >= 3 && eyes <= 4)
            System.out.println("TroyMartian");
        if (ants <= 6 && eyes >= 2)
            System.out.println("VladSaturnian");
        if (ants <= 2 && eyes <= 3)
            System.out.println("GraemeMercurian");

        in.close();
    }
}
