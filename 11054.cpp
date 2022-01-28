#include <stdio.h>

int N;
int num[1000]={0};
int LIS_cnt[1000]={0};
int LDS_cnt[1000]={0};
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
            if(num[i] < num[j] && LIS_cnt[j] < LIS_cnt[i] + 1)
            {
                LIS_cnt[j] = LIS_cnt[i] + 1;
            }
        }
    }
    for(i=N-1;i>=0;i--)
    {
        for(j=i-1;j>=0;j--)
        {
            if(num[i] < num[j] && LDS_cnt[j] < LDS_cnt[i] + 1)
            {
                LDS_cnt[j] = LDS_cnt[i] + 1;
            }
        }
    }

    for(i=0;i<N;i++)
    {
        if(LIS_cnt[i] + LDS_cnt[i] > max)
        {
            max = LIS_cnt[i] + LDS_cnt[i];
        }
    }
    printf("%d", max + 1);
    return 0;
}