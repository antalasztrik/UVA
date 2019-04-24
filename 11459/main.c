#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, a, b, c, i, j, winner, x;
    scanf("%d", &n);
    while(n)
    {
        winner = 0;
        scanf("%d %d %d", &a, &b, &c);

        int *t = calloc(2 * b, sizeof(int));
        int *step = calloc(a, sizeof(int));

        for(i = 0; i < a; i++)
            step[i] = 1;

        for(i = 0; i < 2 * b; i+=2)
            scanf("%d %d", &t[i], &t[i+1]);

        for(i = 0; i < c; i++)
        {
            if(!winner)
            {
                scanf("%d", &x);
                step[i%a] += x;

                for(j = 0; j < 2 * b; j++)
                    if((step[i%a] == t[j]) && !(j%2)){
                        step[i%a] = t[j+1];
                        break;
                    }
            }
            else
                scanf("%d", &x);

            if(step[i%a] >= 100)
            {
                    winner = 1;
                    step[i%a] = 100;
            }
        }

        for(i = 0; i < a; i++)
            printf("Position of player %d is %d.\n", i + 1, step[i]);

        n--;
        free(t);
        free(step);
    }
    return 0;
}
