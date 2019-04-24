#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, db, i, k;
    int *pakk;
    char s[5];
    scanf("%d", &n);
    while(n)
    {
        int t[52] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26,
                 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52};
        int x[52] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26,
                 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52};

        scanf("%d", &db);
        pakk = calloc(db * 52, sizeof(int));

        for(i = 0; i < db * 52; i++)
            scanf("%d\n", &pakk[i]);


        while(gets(s) && strlen(s))
        {
            k = atoi(s);

            for(i = 0; i < 52; i++)
                if(i + 1 != pakk[(k-1)*52 + i])
                    x[i] = t[pakk[(k-1)*52 + i] - 1];

            for(i = 0; i < 52; i++)
                t[i] = x[i];
        }


        for(i = 0; i < 52; i++)
        {
            if(t[i] <= 13)
                switch(t[i] % 13)
                {
                    case 10: printf("Jack of Clubs\n"); break;
                    case 11: printf("Queen of Clubs\n"); break;
                    case 12: printf("King of Clubs\n"); break;
                    case 0: printf("Ace of Clubs\n"); break;
                    default: printf("%d of Clubs\n", (t[i] % 13) + 1); break;
                }

            if(t[i] > 13 && t[i] <= 26)
                switch(t[i] % 13)
                {
                    case 10: printf("Jack of Diamonds\n"); break;
                    case 11: printf("Queen of Diamonds\n"); break;
                    case 12: printf("King of Diamonds\n"); break;
                    case 0: printf("Ace of Diamonds\n"); break;
                    default: printf("%d of Diamonds\n", (t[i] % 13) + 1); break;
                }

            if(t[i] > 26 && t[i] <= 39)
                switch(t[i] % 13)
                {
                    case 10: printf("Jack of Hearts\n"); break;
                    case 11: printf("Queen of Hearts\n"); break;
                    case 12: printf("King of Hearts\n"); break;
                    case 0: printf("Ace of Hearts\n"); break;
                    default: printf("%d of Hearts\n", (t[i] % 13) + 1); break;
                }

            if(t[i] > 39)
                switch(t[i] % 13)
                {
                    case 10: printf("Jack of Spades\n"); break;
                    case 11: printf("Queen of Spades\n"); break;
                    case 12: printf("King of Spades\n"); break;
                    case 0: printf("Ace of Spades\n"); break;
                    default: printf("%d of Spades\n", (t[i] % 13) + 1); break;
                }
        }

        if(n != 1)
            puts("");
        n--;
    }

    return 0;
}





