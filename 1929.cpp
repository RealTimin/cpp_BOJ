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

int main(void)
{
    int M, N;
    int i = 0;
    scanf("%d %d", &M, &N);
    while (prime[lastPrimeIndex] <= N)
    {
        CalculateNextPrime();
    }

    while (prime[i] < M)
    {
        i++;
    }

    while (i < lastPrimeIndex)
    {
        printf("%d\n", prime[i]);
        i++;
    }
}