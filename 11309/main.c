#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int palindrome[2359] = {0};

int solve(int x)
{
    while( palindrome[++x] != 1 && x < 2360 );
    return x == 2360 ? 0 : x;
}


int is_palindrome(int x)
{
    char s[5];
    sprintf(s, "%d", x);

    int b = 0, e = strlen(s) - 1;

    while(e > b)
        if(s[b++] != s[e--])
            return 0;

    return 1;
}

void gen()
{
    int i, j;
    for(i = 0; i < 24; i++)
        for(j = 0; j < 60; j++)
            if(is_palindrome((100 * i) + j))
                palindrome[(100 * i) + j] = 1;
}

int main()
{
    gen();
    int N, result;
    char s[6];
    scanf("%d", &N);
    while(N--)
    {
        scanf("%s", s);
        result = solve(100 * atoi(strtok(s, ":")) + atoi(strtok(NULL, "")));
        printf("%02d:%02d\n", result / 100, result % 100);
    }
    return 0;
}
