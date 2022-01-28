
// #include <stdio.h>
#include <cstdio>

int N;
int num[1000] = {0};
int length[1000] = {0};
int memory[1000][1000] = {0};

int max = 0;
int max_i = 0;

int main(void)
{
    int i, j, k;
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        scanf("%d", &num[i]);
    }
    for (i = 0; i < N; i++)
    {
        for (j = i + 1; j < N; j++)
        {
            if (num[i] < num[j] && length[j] < length[i] + 1)
            {
                for (k = 0; k < length[i]; k++)
                {
                    memory[j][k] = memory[i][k];
                }
                memory[j][k] = num[i];
                length[j] = length[i] + 1;
            }
        }
    }

    for (i = 0; i < N; i++)
    {
        if (length[i] > max)
        {
            max = length[i];
            max_i = i;
        }
    }
    printf("%d\n", max + 1);
    for(i=0;i<max;i++)
    {
        printf("%d ", memory[max_i][i]);
    }
    printf("%d", num[max_i]);
    return 0;
}