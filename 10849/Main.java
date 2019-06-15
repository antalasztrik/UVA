import java.util.Scanner;

public class Main {
    static Scanner sc = new Scanner(System.in);
    public static void main(String[] args) {
        int C, T, N, bishopRow, bishopColumn, squareRow, squareColumn, result;
        String[] positions;
        C = Integer.parseInt(sc.nextLine());
        while(C > 0){
            sc.nextLine();
            T = Integer.parseInt(sc.nextLine());
            N = Integer.parseInt(sc.nextLine());
            while(T > 0){
                positions = sc.nextLine().split("\\s+");
                bishopRow = Integer.parseInt(positions[0]);
                bishopColumn = Integer.parseInt(positions[1]);
                squareRow = Integer.parseInt(positions[2]);
                squareColumn = Integer.parseInt(positions[3]);
                result = solve( Math.abs(bishopRow - squareRow), Math.abs(bishopColumn - squareColumn));
                print(result);
                T--;
            }

            C--;
        }
    }

    private static void print(int result) {
        if(result != -1)
            System.out.println(result);
        else
            System.out.println("no move");
    }

    private static int solve(int rowDiff, int columnDiff) {
        if(rowDiff == 0 && columnDiff == 0)
            return 0;

        if((rowDiff % 2) == (columnDiff % 2)){
            if(rowDiff == columnDiff)
                return 1;
            return 2;
        }

        return -1;
    }
}
