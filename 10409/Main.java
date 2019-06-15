import java.util.Scanner;

public class Main {
    static Scanner sc = new Scanner(System.in);
    public static void main(String[] args) {
        int rolls, top, north, west, temporary;
        String command;
        while((rolls = Integer.parseInt(sc.nextLine())) != 0){
            top = 1;
            north = 2;
            west = 3;

            while(rolls > 0){
                command = sc.nextLine();

                if(command.equals("north")){
                    temporary = top;
                    top = 7 - north;
                    north = temporary;
                }

                if(command.equals("west")){
                    temporary = top;
                    top = 7 - west;
                    west= temporary;
                }

                if(command.equals("south")){
                    temporary = top;
                    top = north;
                    north = 7 - temporary;
                }

                if(command.equals("east")){
                    temporary = top;
                    top = west;
                    west = 7 - temporary;
                }

                rolls--;
            }

            System.out.println(top);
        }
    }
}
