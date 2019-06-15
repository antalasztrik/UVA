import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    static Scanner sc = new Scanner(System.in);
    static String word;
    static String guess;
    static List<Character> letters = new ArrayList<>();
    static int count;
    public static void main(String[] args) {
        int round, result;
        while((round = Integer.parseInt(sc.nextLine())) != -1){
            word = sc.nextLine();
            guess = sc.nextLine();
            init();
            result = solve(guess);
            print(result, round);
        }
    }

    private static void print(int result, int round) {
        System.out.println("Round " + round);
        if(result == 1)
            System.out.println("You win.");

        if(result == 0)
            System.out.println("You chickened out.");

        if(result == -1)
            System.out.println("You lose.");
    }

    private static int solve(String g) {
        int stroke = 0, i;
        List<Character> alreadyGuessed = new ArrayList<>();

        for(i = 0; i < guess.length(); i++){
            if(letters.contains(guess.charAt(i))){
                letters.remove(new Character(guess.charAt(i)));
                alreadyGuessed.add(guess.charAt(i));

                if(letters.size() == 0)
                    return 1;
            }
            else{
                if(!alreadyGuessed.contains(guess.charAt(i))){
                    stroke++;
                    alreadyGuessed.add(guess.charAt(i));
                }

                if(stroke == 7)
                    return -1;
            }
        }

        //System.out.println(stroke + " " + count + " " + alreadyGuessed.size());
        return 0;
    }

    private static void init() {
        int i;
        letters = new ArrayList<>();
        for(i = 0, count = 0; i < word.length(); i++){
            if(!letters.contains(word.charAt(i))){
                letters.add(word.charAt(i));
                count++;
            }
        }
    }
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int letters[26] = {0}, count;
char word[1000] = {0}, guess[30] = {0};

int solve()
{
    int stroke = 0, i;

    for(i = 0; guess[i]; i++){
        if(letters[guess[i] - 'a'] == 1){
            letters[guess[i] - 'a'] = 2;
            count--;
            if(count == 0)
                return 1;
        }

        else{
            if(letters[guess[i] - 'a'] == 0){
                letters[guess[i] - 'a'] = -1;
                stroke++;
            }
            if(stroke == 7)
                return -1;
        }
    }

    return 0;
}

void init(){
    int i;
    count = 0;
    memset(letters, 0, sizeof(int) * 26);
    for(i = 0; word[i]; i++){
        if(letters[word[i] - 'a'] == 0){
            letters[word[i] - 'a'] = 1;
            count++;
        }
    }
}

void print(int result, int round){
    printf("Round %d\n", round);
    if(result == 1)
        puts("You win.");
    if(result == 0)
        puts("You chickened out.");
    if(result == -1)
        puts("You lose.");
}

int main()
{
    int R, result;
    while(scanf("%d", &R) && (R != -1)){
        scanf("%s %s", word, guess);
        init();
        result = solve();
        print(result, R);
    }
    return 0;
}

 */
