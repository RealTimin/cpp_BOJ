#include <stdio.h>

int max(int a, int b)
{
    return a>b?a:b;
}

int main(void)
{
    int i, j, N;
    int sum[500][500]={0};
    int result=0;
    scanf("%d", &N);
    scanf("%d", &sum[0][0]);
    for(i=1;i<N;i++)
    {
        for(j=0;j<i+1;j++)
        {
            scanf("%d", &sum[i][j]);
            if(j==0)
            {
                sum[i][j] += sum[i-1][j];
            }
            else if(j==i)
            {
                sum[i][j]+= sum[i-1][j-1];
            }
            else
            {
                sum[i][j] += max(sum[i-1][j],sum[i-1][j-1]);
            }
        }
    }

    for(i=0;i<N;i++)
    {
        result = max(result, sum[N-1][i]);
    }
    printf("%d", result);
    return 0;
}