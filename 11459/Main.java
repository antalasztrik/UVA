import java.util.Scanner;

public class Main {
    static Scanner sc = new Scanner(System.in);
    static int[] players = new int[1000000];
    public static void main(String[] args) {
        int N, a, b, c, i, roll, current;
        boolean winner;
        N = Integer.parseInt(sc.nextLine());
        while(N > 0){
            winner = false;
            String[] data = sc.nextLine().split(" ");

            a = Integer.parseInt(data[0]);
            b = Integer.parseInt(data[1]);
            c = Integer.parseInt(data[2]);

            int[] step = new int[101];

            for(i = 0; i < a; i++)
                players[i] = 1;

            for(i = 0; i < 101; i++)
                step[i] = i;

            for(i = 0; i < b; i++){
                String[] snakeLadder = sc.nextLine().split(" ");
                step[Integer.parseInt(snakeLadder[0])] = Integer.parseInt(snakeLadder[1]);
            }

            for(i = 0; i < c; i++){
                roll = Integer.parseInt(sc.nextLine());
                if(!winner){
                    current = players[i % a] + roll;
                    if(step[current] < 100){
                        players[i % a] = step[current];
                    }
                    else{
                        players[i % a] = 100;
                        winner = true;
                    }
                }
            }

            for(i = 0; i < a; i++)
                System.out.println("Position of player " + (i + 1) + " is " + players[i] + ".");

            N--;
        }
    }
}
