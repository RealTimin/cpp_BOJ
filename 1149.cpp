// #include <stdio.h>

// int cost[1000][3];
// int sum[1001]={0};
// int N;
// int min = 1000000;

// void bt(int k, int before)
// {
//     if(k==N)
//     {
//         if(sum[N] < min)
//         {
//             min = sum[N];
//         }
//         return;
//     }
//     int i;
//     for(i=0;i<3;i++)
//     {
//         if(i==before)
//         {
//             continue;
//         }
//         sum[k+1] = sum[k] + cost[k][i];
//         bt(k+1, i);
//     }
// }

// int main(void)
// {
//     int i, j;
//     scanf("%d", &N);
//     for(i=0;i<N;i++)
//     {
//         for(j=0;j<3;j++)
//         {
//             scanf("%d", &cost[i][j]);
//         }
//     }
//     bt(0, -1);
//     printf("%d", min);
//     return 0;
// }

#include <stdio.h>

int min(int a, int b)
{
    return a > b ? b : a;
}

int main(void)
{
    int sum[1001][3] = {0};
    int input[3] = {0};
    int i, j, N;
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < 3; j++)
        {
            scanf("%d", &input[j]);
        }
        sum[i+1][0] = input[0] + min(sum[i][1], sum[i][2]);
        sum[i+1][1] = input[1] + min(sum[i][0], sum[i][2]);
        sum[i+1][2] = input[2] + min(sum[i][1], sum[i][0]);
    }
    printf("%d", min(min(sum[i][0], sum[i][1]), sum[i][2]));
    return 0;
}
