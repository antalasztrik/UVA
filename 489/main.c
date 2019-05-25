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
