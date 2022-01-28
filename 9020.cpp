#include <stdio.h>

int prime[100000] = {2, 0};
int lastPrimeIndex = 0;

void CalculateNextPrime(void)
{
    int num = prime[lastPrimeIndex];
    int i;
    int isPrime = false;
    while (!isPrime)
    {
        num++;
        isPrime = true;
        for (i = 0; prime[i] * prime[i] <= num; i++)
        {
            if (num % prime[i] == 0)
            {
                isPrime = false;
                break;
            }
        }
    }
    lastPrimeIndex++;
    prime[lastPrimeIndex] = num;
}

int CheckPrime(int num)
{
    int isPrime = 1;
    int i;
    for (i = 0; prime[i] * prime[i] <= num; i++)
    {
        if (prime[i] == 0)
        {
            CalculateNextPrime();
            i--;
            continue;
        }
        if (num % prime[i] == 0)
        {
            isPrime = 0;
            break;
        }
    }
    return isPrime;
}

int main(void)
{
    int T, N, half_N, currentTest, i, x, y;
    scanf("%d", &T);
    for (currentTest = 0; currentTest < T; currentTest++)
    {
        scanf("%d", &N);
        half_N = N / 2;
        while (prime[lastPrimeIndex] <= N)
        {
            CalculateNextPrime();
        }
        for (i = 0; prime[i] <= half_N; i++)
        {
            if (CheckPrime(N - prime[i]))
            {
                x = prime[i];
                y = N - prime[i];
            }
        }
        printf("%d %d \n", x, y);
    }
    return 0;
}