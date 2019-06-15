import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    static Scanner sc = new Scanner(System.in);
    static int[] palindrome = new int[2360];
    public static void main(String[] args) {
        gen();
        int n, x, z;
        String s;
        n = Integer.parseInt(sc.nextLine());
        while(n > 0){
            s = sc.nextLine();
            x = 1000 * (s.charAt(0) - 48) + 100 * (s.charAt(1) - 48) + 10 * (s.charAt(3) - 48) + (s.charAt(4) - 48);
            z = solve(x);
            System.out.printf("%02d:%02d\n", z / 100, z % 100);
            n--;
        }
    }

    private static int solve(int x) {
        x++;
        while(palindrome[x % 2360] != 1)
            x++;

        return x % 2360;
    }

    private static boolean palind(int x) {
        int b = 0, e;
        String s = String.valueOf(x);
        e = s.length() - 1;

        if(x % 100 >= 60)
            return false;

        while(e > b)
        {
            if(s.charAt(b++) != s.charAt(e--))
                return false;
        }

        return true;
    }

    private static void gen() {
        int i;
        for(i = 0; i < 2359; i++)
            if(palind(i))
                palindrome[i] = 1;
    }
}
