#include <stdio.h>

#define MOD 15746

int fibo[1000001]={1,1};
int lastIndex=1;

void calculateFibo(int N)
{
    while(lastIndex < N)
    {
        lastIndex++;
        fibo[lastIndex] = (fibo[lastIndex-1]+fibo[lastIndex-2]) % MOD;
    }
    return;
}

int main(void)
{
    int N;
    scanf("%d", &N);
    calculateFibo(N);
    printf("%d", fibo[N]);
    return 0;
}