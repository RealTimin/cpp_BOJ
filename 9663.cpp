#include <stdio.h>

int board[15][15] = {0};
int usedCol[15] = {0};
int count = 0;
int n;

void PutQueen(int k)
{
    if (k == n)
    {
        count++;
        return;
    }
    int row, col;
    int i, j;
    int possible;
    row = k;
    for (col = 0; col < n; col++)
    {
        possible = true;
        for (i = 0; i < k; i++)
        {
            if (usedCol[i] == col)
            {
                possible = false;
                break;
            }
        }
        i = row;
        j = col;
        while (possible && i >= 0 && j < n)
        {
            if (board[i--][j++])
            {
                possible = false;
                break;
            }
        }
        i = row;
        j = col;
        while (possible && i >= 0 && j >= 0)
        {
            if (board[i--][j--])
            {
                possible = false;
                break;
            }
        }
        if (possible)
        {
            board[row][col] = 1;
            usedCol[k] = col;
            PutQueen(k + 1);
            board[row][col] = 0;
        }
    }
}

int main(void)
{
    scanf("%d", &n);
    PutQueen(0);
    printf("%d", count);
    return 0;
}