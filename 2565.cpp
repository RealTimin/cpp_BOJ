#include <stdio.h>

int N;
int num[500] = {0};
int length[500] = {0};
int max = 0;

int main(void)
{
    int i, j, index;
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        scanf("%d", &index);
        scanf("%d", &num[index - 1]);
    }

    for (i = 0; i < 500; i++)
    {
        for (j = i + 1; j < 500; j++)
        {
            if (num[i] != 0 && num[i] < num[j] && length[j] < length[i] + 1)
            {
                length[j] = length[i] + 1;
            }
        }
    }

    for (i = 0; i < 500; i++)
    {
        if (length[i] > max)
        {
            max = length[i];
        }
    }
    printf("%d", N - (max + 1));
    return 0;
}