#include <stdio.h>
#include <stdlib.h>

int solve(int x, int y)
{
    if(x == 0 && y == 0)
        return 1;

    if((x%2) == (y%2))
    {
        if(x == y)
            return 2;
        return 3;
    }

    return 0;
}

int main()
{
    int C, T, N, br, bc, tr, tc, sol;
    scanf("%d", &C);
    while(C--)
    {
        scanf("%d", &T);
        scanf("%d", &N);
        while(T--)
        {
            scanf("%d %d %d %d", &br, &bc, &tr, &tc);
            sol = solve(abs(br - tr), abs(bc - tc));
            if(sol)
                printf("%d\n", sol - 1);
            else
                printf("no move\n");
        }
    }
    return 0;
}
