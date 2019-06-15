import java.util.Scanner;

public class Main {
    static Scanner sc = new Scanner(System.in);
    public static void main(String[] args) {
        int N, i;
        String cards;
        N = Integer.parseInt(sc.nextLine());
        for(i = 0; i < N; i++){
            cards = sc.nextLine();

            System.out.println("Case " + (i + 1) + ": " + cards.charAt(96) + cards.charAt(97));
        }
    }
}
