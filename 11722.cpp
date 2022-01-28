
#include <stdio.h>

int N;
int num[1000]={0};
int length[1000]={0};
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
            if(num[i] > num[j] && length[j] < length[i] + 1)
            {
                length[j] = length[i] + 1;
            }
        }
    }

    for(i=0;i<N;i++)
    {
        if(length[i] > max)
        {
            max = length[i];
        }
    }
    printf("%d", max + 1);
    return 0;
}