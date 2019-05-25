#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int set = 0;
int deck[2][52];
int shuffles[100][52];

char *names[] = { "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
char *color[] = { "Clubs", "Diamonds", "Hearts", "Spades"};

void shuffle(int n){
    int i;
    for(i = 0; i < 52; i++)
        deck[1 - set][i] = deck[set][ shuffles[n][i] - 1 ];
    set = 1 - set;
}


void get_shuffles(){
    int i, j, n;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        for(j = 0; j < 52; j++)
            scanf("%d\n", &shuffles[i][j]);
}


void solve(){
    char s[5];
    while(gets(s) && strlen(s))
        shuffle(atoi(s) - 1);
}


void init(){
    int i;
    for(i = 0; i < 52; i++)
        deck[0][i] = deck[1][i] = i + 1;
}


void print(){
    int i;
    for(i = 0; i < 52; i++)
        printf("%s of %s\n", names[ (deck[set][i]) % 13 ], color[ (deck[set][i]-1) / 13 ]);
}


int main()
{
    int N;
    scanf("%d", &N);
    while(N--){
        init();
        get_shuffles();
        solve();
        print();
        if(N > 0) puts("");
    }
    return 0;
}
