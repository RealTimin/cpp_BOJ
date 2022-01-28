
//n(PI)m 구하기.

#include <stdio.h>

void MakeChoice(int *choice, int n, int m, int leftNumCount)
{
    int i;
    if (leftNumCount == 0)
    {
        for (i = 0; i < m; i++)
        {
            printf("%d ", choice[i]);
        }
        printf("\n");
        return;
    }
    else
    {
        int j, isSame;
        for (i = 1; i <= n; i++)
        {
            choice[m-leftNumCount] = i;
            MakeChoice(choice, n, m, leftNumCount - 1);
        }
    }
}

int main(void)
{
    int n, m;
    int choice[8];
    int i, j;
    scanf("%d %d", &n, &m);
    MakeChoice(choice, n, m, m);
    return 0;
}
