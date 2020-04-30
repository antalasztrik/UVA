import java.util.Scanner;

public class Main {
    static private int[] t = new int[1000];
    static private Scanner sc = new Scanner(System.in);
    static private int N, game = 1;
    public static void main(String[] args) {
        int i;
        while(sc.hasNextLine()) {
            N = Integer.parseInt(sc.nextLine());
            if (N == 0)
                break;

            System.out.printf("Game %d:\n", game++);
            String[] items;
            items = sc.nextLine().split(" ");
            for(i = 0; i < N; i++) {
                t[i] = Integer.parseInt(items[i]);
            }

            Solve();
        }
    }

    static void Solve() {
        int strong, weak, i, j;
        int[] arr = new int[N];
        int[] copy = new int[N];
        while(true) {
            strong = weak = 0;
            String[] items;
            items = sc.nextLine().split(" ");
            for(i = 0; i < N; i++) {
                arr[i] = Integer.parseInt(items[i]);
                copy[i] = t[i];
            }

            if (arr[0] == 0)
                break;

            for(i = 0; i < N; i++) {
                if (arr[i] == copy[i]) {
                    strong++;
                    copy[i] = arr[i] = 0;
                }
            }

            for(i = 0; i < N; i++){
                for(j = 0; j < N; j++){
                    if(arr[i] == copy[j] && arr[i] > 0){
                        weak++;
                        copy[j] = 0;
                        break;
                    }
                }
            }

            System.out.printf("    (%d,%d)\n", strong, weak);
        }
    }
}
