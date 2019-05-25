#include <stdio.h>
#include <stdlib.h>

/*int main()
{
    int N, i, Y, j, k, l;
    scanf("%d", &N);
    char t[52][3];
    for(i = 0; i < N; i++)
    {
        Y = 0;
        l = 27;
        for(j = 0; j < 52; j++)
            scanf("%s", t[j]);

        for(k = 0; k < 3; k++)
        {
            if(t[l][0] == 'A' || t[l][0] == 'K' || t[l][0] == 'Q' || t[l][0] == 'J' || t[l][0] == 'T')
            {
                Y += 11;
                l--;
            }
            else
            {
                Y += 11;
                l -= 10 - t[l][0] + 1;
            }
        }
        printf("Case %d: %s\n", i + 1, t[Y - 1]);
    }
    return 0;
}*/

int main()
{
    int N, i, j;
    char card[3];
    scanf("%d", &N);
    for(i = 0; i < N; i++){
        for(j = 0; j < 52; j++) {
            scanf("%s", card);
            if(j == 32)
                printf("Case %d: %s\n", i + 1, card);
        }
    }
    return 0;
}
