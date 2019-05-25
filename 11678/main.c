#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Anum, Bnum;
int adeck[100000], bdeck[100000];

void init(){
    Anum = Bnum = 0;
    memset(adeck, 0, sizeof(int) * 100000);
    memset(bdeck, 0, sizeof(int) * 100000);
}

void input(int A, int B){
    int i, num;
    for(i = 0; i < A; i++)
    {
        scanf("%d", &num);
        adeck[num]++;
    }

    for(i = 0; i < B; i++)
    {
        scanf("%d", &num);
        bdeck[num]++;
    }
}

int solve(){
    int i, Anum, Bnum;
    for(i = 0; i < 100000; i++)
    {
        if(adeck[i] != 0 && bdeck[i] == 0)
            Anum++;

        if(adeck[i] == 0 && bdeck[i] != 0)
            Bnum++;
    }

    return Anum < Bnum ? Anum: Bnum;
}

int main()
{
    int A, B, result;
    while(scanf("%d %d", &A, &B) && A && B)
    {
        init();
        input(A, B);
        result = solve();
        printf("%d\n", result);
    }

    return 0;
}
