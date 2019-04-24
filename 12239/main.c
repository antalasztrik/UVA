#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, B, i, j, good;
    while(scanf("%d %d", &N, &B))
    {
        good = 1;
        if(N == 0 && B == 0)
            break;

        int *t = calloc(B, sizeof(int));
        int *ossz = calloc(N + 1, sizeof(int));

        for(i = 0; i < B; i++)
            scanf("%d", &t[i]);

        for(i = 0; i < B; i++)
            for(j = 0; j < B; j++)
                ossz[abs(t[i] - t[j])]++;

        for(i = 0; i < N + 1; i++)
            if(ossz[i] == 0)
                good = 0;

        printf("%c\n", good ? 'Y' :'N');
        free(t);
        free(ossz);
    }
    return 0;
}
