#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int N, B, i, j, good;
    while(scanf("%d %d", &N, &B))
    {
        good = 1;
        if(N == 0 && B == 0)
            break;

        int t[B];
        int diff[N + 1];

        memset(diff, 0, (N + 1) * sizeof(int));

        for(i = 0; i < B; i++)
            scanf("%d", &t[i]);

        for(i = 0; i < B; i++)
            for(j = 0; j < B; j++)
                diff[abs(t[i] - t[j])]++;

        for(i = 0; i < N + 1; i++)
            if(diff[i] == 0)
                good = 0;

        printf("%c\n", good ? 'Y' :'N');
    }
    return 0;
}
