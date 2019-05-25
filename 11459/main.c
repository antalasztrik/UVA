#include <stdio.h>
#include <stdlib.h>

int players[1000000];

int main()
{
    int N, a, b, c, i, j, winner, x, p;
    scanf("%d", &N);
    while(N--)
    {
        winner = 0;
        scanf("%d %d %d", &a, &b, &c);
        int step[101];

        for(i = 0; i < a; i++)
            players[i] = 1;

        for(i = 0; i < 101; i++)
            step[i] = i;

        for(i = 0; i < b; i++){
            scanf("%d %d", &x, &p);
            step[x] = p;
        }

        for(i = 0; i < c; i++)
        {
            scanf("%d", &x);
            if(!winner)
            {
                j = players[i%a] + x;
                if(step[j] < 100)
                    players[i%a] = step[j];
                else
                {
                    players[i%a] = 100;
                    winner = 1;
                }
            }
        }

        for(i = 0; i < a; i++)
            printf("Position of player %d is %d.\n", i + 1, players[i]);
    }
    return 0;
}
