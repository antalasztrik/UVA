#include <stdio.h>
#include <stdlib.h>

int solve(int x, int y)
{
    if(x == 0 && y == 0)
        return 0;

    if((x % 2) == (y % 2))
    {
        if(x == y)
            return 1;
        return 2;
    }

    return -1;
}

void print(int result){
    if(result != -1)
        printf("%d\n", result);
    else
        puts("no move");
}

int main()
{
    int C, T, N, brow, bcol, trow, tcol, result;
    scanf("%d", &C);
    while(C--)
    {
        scanf("%d %d", &T, &N);
        while(T--)
        {
            scanf("%d %d %d %d", &brow, &bcol, &trow, &tcol);
            result = solve( abs(brow - trow), abs(bcol - tcol));
            print(result);
        }
    }
    return 0;
}
