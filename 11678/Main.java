import java.util.Scanner;

public class Main {
    static Scanner sc = new Scanner(System.in);
    static int Anum, Bnum;
    static int[] adeck;
    static int[] bdeck;
    public static void main(String[] args) {
        int A, B, result;
        String[] cardsNum = sc.nextLine().split(" ");
        while((A = Integer.parseInt(cardsNum[0])) > 0 && (B = Integer.parseInt(cardsNum[1])) > 0){
            init();
            input(A, B);
            result = solve();
            System.out.println(result);
            cardsNum = sc.nextLine().split(" ");
        }
     }

    private static int solve() {
        int i;
        for(i = 0; i < 100000; i++){
            if(adeck[i] != 0 && bdeck[i] == 0)
                Anum++;

            if(adeck[i] == 0 && bdeck[i] != 0)
                Bnum++;
        }

        return Anum < Bnum ? Anum: Bnum;
    }

    private static void input(int A, int B) {
        int i, num;
        String[] cards = sc.nextLine().split(" ");

        for(i = 0; i < A; i++){
            num = Integer.parseInt(cards[i]);
            adeck[num]++;
        }

        cards = sc.nextLine().split(" ");

        for(i = 0; i < B; i++){
            num = Integer.parseInt(cards[i]);
            bdeck[num]++;
        }
    }

    private static void init() {
        Anum = Bnum = 0;
        adeck = new int[100000];
        bdeck = new int[100000];
    }
}
