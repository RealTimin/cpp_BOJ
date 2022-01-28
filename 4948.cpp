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
    int N;
    int N_times_2;
    int i;
    int count;
    scanf("%d", &N);
    while (N)
    {
        N_times_2 = N * 2;
        i = 0;
        count = 0;
        while (prime[lastPrimeIndex] <= N_times_2)
        {
            CalculateNextPrime();
        }

        while (prime[i] <= N)
        {
            i++;
        }

        while (prime[i] <= N_times_2 && i <= lastPrimeIndex)
        {
            i++;
            count++;
        }
        // printf("%d %d ", i, prime[i-1]);
        printf("%d\n", count);
        scanf("%d", &N);
    }
    return 0;
}