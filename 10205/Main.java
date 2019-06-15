import java.util.Scanner;

public class Main {
    static int Set = 0;
    static int[][] Deck = new int[2][52];
    static int[][] Shuffles = new int[100][52];
    static String[] Names = new String[]{ "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
    static String[] Color = new String[]{ "Clubs", "Diamonds", "Hearts", "Spades"};
    static Scanner sc  = new Scanner(System.in);
    public static void main(String[] args) {
        int N;
        N = Integer.parseInt(sc.nextLine());
        sc.nextLine();
        while(N-- != 0){
            init();
            get_shuffles();
            solve();
            print();
            if(N > 0)
                System.out.println();
        }
    }

    private static void print() {
        int i;
        for(i = 0; i < 52; i++)
            System.out.println(Names[ (Deck[Set][i]) % 13] + " of " + Color[ (Deck[Set][i]-1) / 13]);
    }

    private static void solve() {
        String numShuffle;
            while (sc.hasNextLine() && !(numShuffle = sc.nextLine()).equals("")) {
                shuffle(Integer.parseInt(numShuffle) - 1);
            }
    }

    private static void shuffle(int n){
        int i;
        for(i = 0; i < 52; i++) {
            if(Shuffles[n][i] == 0)
                System.out.println(n + " " + i);
            Deck[1 - Set][i] = Deck[Set][Shuffles[n][i] - 1];
        }
        Set = 1 - Set;
    }

    private static void get_shuffles() {
        int i, j, n, cardCounter;
        n = Integer.parseInt(sc.nextLine());
        for(i = 0; i < n; i++) {
            cardCounter = 0;
            while(cardCounter != 52) {
                String[] x = sc.nextLine().split(" ");
                for (j = cardCounter; j < cardCounter + x.length; j++) {
                    Shuffles[i][j] = Integer.parseInt(x[j - cardCounter]);
                }
                cardCounter += x.length;
            }
        }
    }

    private static void init() {
        int i;
        for(i = 0; i < 52; i++)
            Deck[0][i] = Deck[1][i] = i + 1;
    }
}
