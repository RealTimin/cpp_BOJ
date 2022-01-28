#include <stdio.h>

int fibo[41]={0,1};
int lastIndex=1;

void printFibo(int N)
{
    while(lastIndex < N)
    {
        lastIndex++;
        fibo[lastIndex] = fibo[lastIndex-1]+fibo[lastIndex-2];
    }
    printf("%d ", fibo[N]);
    return;
}

int main(void)
{
    int i, T, N;
    scanf("%d", &T);
    for(i=0;i<T;i++)
    {
        scanf("%d", &N);
        if(N==0)
        {
            printFibo(1);
            printFibo(0);
            printf("\n");
        }
        else
        {
            printFibo(N-1);
            printFibo(N);
            printf("\n");
        }
    }
    return 0;
}