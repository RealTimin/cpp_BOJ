#include <stdio.h>

int table[20][20]={0};
int team[20]={0};
int N;
int half_N;
int min = -1;

int CalDif(void)
{
    int i, j;
    int result_1=0;
    int result_0=0;
    int dif;
    for(i=0; i<N;i++)
    {
        switch (team[i])
        {
        case 1:
            for(j=0;j<N;j++)
            {
                if(team[j]==1)
                {
                    result_1 += table[i][j];
                }
            }
            break;
        case 0:
            for(j=0;j<N;j++)
            {
                if(team[j]==0)
                {
                    result_0 += table[i][j];
                }
            }
            break;
        default:
            printf("err\n");
            break;
        }
    }
    dif = result_1 - result_0;
    return dif>0 ? dif:-dif;
}

void MakeTeam(int k, int startNum)
{
    int i;
    if(k == half_N)
    {
        // for(i=0;i<N;i++)
        //     printf("%d ", team[i]);
        // printf("\n");

        int dif = CalDif();
        // printf("%d\n", dif);
        if(min==-1)
            min = dif;
        else if(dif<min)
            min = dif;
        return;
    }
    for(i=startNum;i<N-half_N+k+1;i++)
    {
        team[i]=1;
        MakeTeam(k+1, i+1);
        team[i]=0;
    }
    return;
}

int main(void)
{
    int i, j;
    scanf("%d", &N);
    for(i=0; i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            scanf("%d", &table[i][j]);
        }
    }
    half_N = N / 2;
    MakeTeam(0,0);
    printf("%d", min);
    return 0;
}