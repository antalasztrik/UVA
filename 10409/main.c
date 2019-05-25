#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int top, north, west;

void init(){
    top = 1;
    north = 2;
    west = 3;
}

void rotate_a(int *a){
    int tmp = top;
    top = 7 - *a;
    *a = tmp;
}

void rotate_b(int *a){
    int tmp = top;
    top = *a;
    *a = 7 - tmp;
}

void solve(int n){
    char s[6];
    for(; n; n--){
        scanf("%s", s);
        if(!strcmp(s, "north")) rotate_a(&north);
        if(!strcmp(s, "west"))  rotate_a(&west);
        if(!strcmp(s, "south")) rotate_b(&north);
        if(!strcmp(s, "east"))  rotate_b(&west);
    }
}

int main()
{
    int db;
    while(scanf("%d", &db) && db)
    {
        init();
        solve(db);
        printf("%d\n", top);
    }
    return 0;
}
