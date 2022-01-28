
#include <stdio.h>

int N;
int num[1000]={0};
int sum[1000]={0};
int max = 0;

int main(void)
{
    int i, j;
    scanf("%d", &N);
    for(i=0;i<N;i++)
    {
        scanf("%d", &num[i]);
    }
    for(i=0;i<N;i++)
    {
        for(j=i+1;j<N;j++)
        {
            if(num[i] < num[j] && sum[j] < sum[i] + num[i])
            {
                sum[j] = sum[i] + num[i];
            }
        }
    }

    for(i=0;i<N;i++)
    {
        if(sum[i] + num[i] > max)
        {
            max = sum[i] + num[i];
        }
    }
    printf("%d", max);
    return 0;
}