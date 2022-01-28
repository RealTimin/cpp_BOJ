// #include <stdio.h>

// int dif[1000][1000] = {0};
// int N;
// int max_length = 0;

// void PrintDif(void)
// {
//     int i, j;
//     for (i = 0; i < N; i++)
//     {
//         for (j = 0; j < N; j++)
//         {
//             printf("%d ", dif[i][j]);
//         }
//         printf("\n");
//     }
// }

// void bt(int col, int depth)
// {
//     int i;
//     for (i = col + 1; i < N; i++)
//     {
//         if (dif[i][col] > 0)
//         {
//             bt(i, depth + 1);
//         }
//     }
//     if(i==N)
//     {
//         if (depth > max_length)
//         {
//             max_length = depth;
//         }
//         return;
//     }
// }

// int main(void)
// {
//     int i, j;
//     int temp = 0, num;
//     int difference;
//     scanf("%d", &N);
//     for (i = 0; i < N; i++)
//     {
//         scanf("%d", &num);
//         difference = num - temp;
//         for (j = 0; j < i - 1; j++)
//         {
//             dif[i][j] = dif[i - 1][j] + difference;
//         }
//         if (j == i - 1)
//         {
//             dif[i][j] = difference;
//         }
//         temp = num;
//     }
//     // PrintDif();
//     bt(0, 1);
//     printf("%d", max_length);
//     return 0;
// }

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
            if(num[i] < num[j] && length[j] < length[i] + 1)
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