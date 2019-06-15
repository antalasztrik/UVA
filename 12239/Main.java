import java.util.Scanner;

public class Main {
    static Scanner sc = new Scanner(System.in);
    public static void main(String[] args) {
        int N, B, i, j;
        boolean good;
        String[] data = sc.nextLine().split(" ");
        String balls;
        N = Integer.parseInt(data[0]);
        B = Integer.parseInt(data[1]);
        while(N != 0 && B != 0){
            good = true;
            int[] t = new int[B];
            int[] sum = new int[N + 1];
            balls = sc.nextLine();

            for(i = 0; i < B; i++)
                t[i] = Integer.parseInt(balls.split(" ")[i]);

            for(i = 0; i < B; i++)
                for(j = 0; j < B; j++)
                    sum[Math.abs(t[i] - t[j])]++;

                for(i = 0; i < N + 1; i++)
                    if(sum[i] == 0)
                        good = false;

            System.out.println(good ? "Y" : "N");

            data = sc.nextLine().split(" ");
            N = Integer.parseInt(data[0]);
            B = Integer.parseInt(data[1]);
        }
    }
}
