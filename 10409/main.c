#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int t, n, w, db, tmp;
    char s[6];
    while(scanf("%d", &db))
    {
        t = 1;
        n = 2;
        w = 3;

        if(!db)
            break;

        while(db)
        {
            scanf("%s", s);
            if(!strcmp(s, "north"))
            {
                tmp = t;
                t = 7 - n;
                n = tmp;
            }

            if(!strcmp(s, "west"))
            {
                tmp = t;
                t = 7 - w;
                w = tmp;
            }

            if(!strcmp(s, "south"))
            {
                tmp = t;
                t = n;
                n = 7 - tmp;
            }

            if(!strcmp(s, "east"))
            {
                tmp = t;
                t = w;
                w = 7 - tmp;
            }

            db--;
        }
        printf("%d\n", t);
    }
    return 0;
}
