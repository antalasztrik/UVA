#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int palindrome[2359] = {0};

int solve(int x)
{
    x++;
    while(palindrome[x % 2360] != 1)
        x++;

    return x % 2360;
}

int palind(int x)
{
    int b = 0, e;
    char s[5];
    sprintf(s, "%d", x);
    e = strlen(s) - 1;

    if(x % 100 >= 60)
        return 0;

    while(e > b)
    {
        if(s[b++] != s[e--])
            return 0;
    }
    return 1;
}

void gen()
{
    int i;
    for(i = 0; i < 2359; i++)
        if(palind(i))
            palindrome[i] = 1;
}

int main()
{
    int n, x, z;
    char s[6];
    scanf("%d", &n);
    gen();
    while(n)
    {
        scanf("%s", s);
        x = 1000 * (s[0] - 48) + 100 * (s[1] - 48) + 10 * (s[3] - 48) + (s[4] - 48);
        z = solve(x);
        printf("%02d:%02d\n", z / 100, z % 100);
        n--;
    }
    return 0;
}

