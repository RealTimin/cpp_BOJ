// #include <stdio.h>

// int sum[100000];
// int num[100000];
// int N;
// int max = -10000;

// int main(void)
// {
//     int i, j;
//     scanf("%d", &N);
//     for (i = 0; i < N; i++)
//     {
//         scanf("%d", &num[i]);
//     }
//     for(i=0;i<N;i++)
//     {
//         for(j=0;j<N-i;j++)
//         {
//             sum[j] += num[j+i];
//             if (sum[j] > max)
//             {
//                 max = sum[j];
//             }
//         }
//     }
//     printf("%d", max);
//     return 0;
// }

// Sn과 S0의 차이 중 가장 큰 것을 고르면 됨. 
// S0~Si까지의 수 중 최솟값을 저장. S_i+1과의 차이를 계산. 

#include <stdio.h>

int sum[100001]={0}; //S0~Sn까지 저장. 
int minOfSumFromZero[100001]={0}; // S0~Si까지의 수 중 최솟값을 저장. 
int max=-1001;  //초기화는 가능한 모든 답보다 작은 수로 한다. 
int N;

int main(void)
{
    int i, temp;
    scanf("%d", &N);

    for(i=1;i<=N;i++)
    {
        scanf("%d", &temp);
        sum[i]=sum[i-1]+temp;
        if(minOfSumFromZero[i-1] > sum[i])
        {
            minOfSumFromZero[i] = sum[i];
        }
        else
        {
            minOfSumFromZero[i] = minOfSumFromZero[i-1];
        }
        if(sum[i]-minOfSumFromZero[i-1] > max)
        {1003
            max=sum[i]-minOfSumFromZero[i-1];
        }
    }
    printf("%d", max);
    return 0;
}