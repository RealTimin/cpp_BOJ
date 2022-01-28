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
    if(num == 1)
        return 0;
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
    int N, i;
    scanf("%d", &N);
    i = 0;
    while (prime[i] * prime[i] <= N)
    {
        if (prime[i] == 0)
        {
            CalculateNextPrime();
            continue;
        }
        i++;
    }

    i=0;
    while (1)
    {
        if(CheckPrime(N))
        {
            printf("%d", N);
            break;
        }
        else if(N==1)
        {
            break;
        }
        if (N % prime[i] == 0)
        {
            printf("%d\n", prime[i]);
            N /= prime[i];
        }
        else
        {
            i++;
        }
    }
    return 0;
}