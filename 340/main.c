#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int t[1000] = {0}, N, game = 1;

void solve()
{
    int strong, weak, i, j;
    int arr[N], copy[N];
    while(1){
        strong = weak = 0;
        for(i = 0; i < N; i++){
            scanf("%d", &arr[i]);
            copy[i] = t[i];
        }

        if(arr[0] == 0)
            break;

        for(i = 0; i < N; i++){
            if(arr[i] == copy[i]){
                strong++;
                copy[i] = arr[i] = 0;
            }
        }

        for(i = 0; i < N; i++){
            for(j = 0; j < N; j++){
                if(arr[i] == copy[j] && arr[i] > 0){
                    weak++;
                    copy[j] = 0;
                    break;
                }
            }
        }

        printf("    (%d,%d)\n", strong, weak);
    }
}

int main()
{
    int i;
    while(scanf("%d", &N))
    {
        if(N == 0)
            break;

        printf("Game %d:\n", game++);

        for(i = 0; i < N; i++){
            scanf("%d", &t[i]);
        }

        solve();
    }
    return 0;
}
