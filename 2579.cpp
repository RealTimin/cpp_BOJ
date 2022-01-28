#include <stdio.h>

int max_1_before[301];
int max_2_before[301];
int N;

int main(void)
{
    int i, stair;
    scanf("%d", &N);
    scanf("%d", &stair);
    max_1_before[1] = stair;
    max_2_before[1] = stair;
    for(i=2;i<=N;i++)
    {
        scanf("%d", &stair);
        max_1_before[i] = max_2_before[i-1] + stair;
        max_2_before[i] = ( max_1_before[i-2] > max_2_before[i-2] ? max_1_before[i-2] : max_2_before[i-2] ) + stair;
    }
    printf("%d", max_1_before[N] > max_2_before[N] ? max_1_before[N] : max_2_before[N]);
    return 0;
}

// #include <stdio.h>
// int m1[301];
// int m2[301];
// int N,i,s;
// int main(void){
//     scanf("%d",&N);
//     scanf("%d",&s);
//     m1[1]=s;
//     m2[1]=s;
//     for(i=2;i<=N;i++)    {
//         scanf("%d",&s);
//         m1[i]=m2[i-1]+s;
//         m2[i]=(m1[i-2]>m2[i-2]?m1[i-2]:m2[i-2])+s;
//     }
//     printf("%d",m1[N]>m2[N]?m1[N]:m2[N]);
//     return 0;
// }