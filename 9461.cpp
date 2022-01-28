#include <stdio.h>

unsigned long long P[1000] = {0};
int lastPIndex;

void CalculateNextP(void)
{
    lastPIndex++;
    P[lastPIndex] = P[lastPIndex - 1] + P[lastPIndex - 5];
    return;
}

int main(void)
{
    int T, i, N;
    P[1] = 1;
    P[2] = 1;
    P[3] = 1;
    P[4] = 2;
    P[5] = 2;
    lastPIndex = 5;
    scanf("%d", &T);
    for (i = 0; i < T; i++)
    {
        scanf("%d", &N);
        while (N > lastPIndex)
        {
            CalculateNextP();
        }
        printf("%llu\n", P[N]);
    }
    return 0;
}