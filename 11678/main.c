#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int A, B, An, Bn, N, i;
    int AK[100000], BK[100000];
    while(scanf("%d %d", &A, &B))
    {
        if(A == 0 && B == 0)
            break;

        An = Bn = 0;
        memset(AK, 0, sizeof(int) * 100000);
        memset(BK, 0, sizeof(int) * 100000);

        for(i = 0; i < A; i++)
        {
            scanf("%d", &N);
            AK[N]++;
        }

        for(i = 0; i < B; i++)
        {
            scanf("%d", &N);
            BK[N]++;
        }

        for(i = 0; i < 100000; i++)
        {
            if(AK[i] != 0 && BK[i] == 0)
                An++;

            if(AK[i] == 0 && BK[i] != 0)
                Bn++;
        }

        printf("%d\n", An < Bn ? An : Bn);

    }
    return 0;
}
