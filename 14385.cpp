#include <stdio.h>

int prime[100000] = {2, 0};
int lastPrimeIndex = 0;

int IncreaseJam(int *num, int N)
{
    int i;
    for (i = N - 2; i > 0; i--)
    {
        if (num[i] == 0)
        {
            num[i] = 1;
            break;
        }
        else
        {
            num[i] = 0;
        }
    }
    if (i)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

unsigned long long NumberInBase(int *num, int N, int base)
{
    unsigned long long result = 0;
    unsigned long long temp = 1;
    int i, j;
    for (i = 0; i < N; i++)
    {
        if (num[i])
        {
            temp = 1;
            for (j = 0; j < N - 1 - i; j++)
            {
                temp *= base;
            }
            result += temp;
        }
    }
    return result;
}

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

int CheckPrimeAndReturnDivisor(unsigned long long num)
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

    if (isPrime)
    {
        return 0;
    }
    else
    {
        return prime[i]; //return divisor
    }
}

int main(void)
{
    int num[32] = {0};
    int T, N, J;
    int base;
    unsigned long long codeNum;
    int divisors[9];
    int divisor;
    int isJam;
    int i, currentTest;
    scanf("%d", &T);
    scanf("%d %d", &N, &J);
    num[0] = 1;
    num[N - 1] = 1;

    // for(int i=0; i<10; i++)
    // {
    //     CalculateNextPrime();
    //     printf("%d ", prime[i]);
    // }
    for (currentTest = 0; currentTest < T; currentTest++)
    {
        printf("Case #%d: \n", currentTest + 1);
        while (J)
        {
            isJam = 1;
            for (base = 2; base < 11; base++)
            {
                codeNum = NumberInBase(num, N, base);
                divisor = CheckPrimeAndReturnDivisor(codeNum);
                if (divisor)
                {
                    divisors[base - 2] = divisor;
                }
                else
                {
                    isJam = 0;
                    break;
                }
            }

            if (isJam)
            {
                for (i = 0; i < N; i++)
                {
                    printf("%d", num[i]);
                }
                printf(" ");
                for (i = 0; i < 9; i++)
                {
                    printf("%d ", divisors[i]);
                }
                printf("\n");
                J--;
            }

            if (IncreaseJam(num, N) == -1)
            {
                printf("Searched all %d length JamCoin. left: %d JamCoin", N, J);
                break;
            }
        }
    }
    return 0;
}