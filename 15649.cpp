
//nPm 구하기.

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
            for (j = 0; j < m - leftNumCount; j++)
            {
                isSame = 0;
                if (choice[j] == i)
                {
                    isSame = 1;
                    break;
                }
            }
            if (!isSame)
            {
                choice[m-leftNumCount] = i;
                MakeChoice(choice, n, m, leftNumCount - 1);
            }
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
