#define MOD 1000000000

#include <stdio.h>

int stair[101][10]={0};

int main(void)
{
    int N, i, j;
    int sum=0;
    for(j=1;j<10;j++)
    {
        stair[1][j] = 1;
    }
    scanf("%d", &N);
    for(i=2;i<=N;i++)
    {
        stair[i][0] = stair[i-1][1];
        for(j=1;j<9;j++)
        {
            stair[i][j] = (stair[i-1][j-1] + stair[i-1][j+1]) % MOD;
        }
        stair[i][9] = stair[i-1][8];
    }
    for(j=0;j<10;j++)
    {
        sum += stair[N][j];
        sum %= MOD;
    }
    printf("%d", sum);
    return 0;
}