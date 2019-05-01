#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hangman(char *s1, char *s2)
{
    int stroke = 0, i, db = 0;
    int betuk[26] = {0};
    for(i = 0; s1[i]; i++)
        if(betuk[s1[i] - 'a'] == 0){
            betuk[s1[i] - 'a'] = 1;
            db++;
        }

    for(i = 0; s2[i]; i++){
        if(betuk[s2[i] - 'a'] == 1){
            betuk[s2[i] - 'a'] = 2;
            db--;
            if(db == 0)
                return 1;
        }
        else{
            if(betuk[s2[i] - 'a'] == 0)
            {
                betuk[s2[i] - 'a'] = -1;
                stroke++;
            }
            if(stroke == 7)
                return 0;
        }
    }

    return -1;
}


int main()
{
    int i, x;
    char szo[1000] = {0}, tipp[30] = {0};
    while(scanf("%d", &i) && i != -1){
        scanf("%s", szo);
        scanf("%s", tipp);
        x = hangman(szo, tipp);
        if(x == 1)
            printf("Round %d\nYou win.\n", i);
        if(x == -1)
            printf("Round %d\nYou chickened out.\n", i);
        if(x == 0)
            printf("Round %d\nYou lose.\n", i);
    }
    return 0;
}
