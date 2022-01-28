#include <stdio.h>

int board[9][9] = {0};
int zero[81][2] = {0};
int zeroCount = 0;
int cnt=0;

void PrintBoard(void)
{
    int i, j;
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int Check(int row, int col)
{
    int i, j;
    int possible = true;
    for (i = 0; i < 9; i++)
    {
        if (possible && i != row && board[i][col] == board[row][col])
        {
            possible = false;
        }
    }
    for (j = 0; j < 9; j++)
    {
        if (possible && j != col && board[row][j] == board[row][col])
        {
            possible = false;
        }
    }
    for (i = (row / 3) * 3; i < (row / 3 + 1) * 3; i++)
    {
        for (j = (col / 3) * 3; j < (col / 3 + 1) * 3; j++)
        {
            if (possible && (i != row || j != col) && board[i][j] == board[row][col])
            {
                possible = false;
            }
        }
    }
    return possible;
}

int Fill(int fillCount)
{
    if (fillCount == zeroCount)
    {
        PrintBoard();
        return 0;
    }
    int i;
    for (i = 1; i < 10; i++)
    {
        board[zero[fillCount][0]][zero[fillCount][1]] = i;
        if (Check(zero[fillCount][0], zero[fillCount][1]))
        {
            if (Fill(fillCount + 1)==0) //solution not found
            {
                return 0;
            }
        }
    }
    board[zero[fillCount][0]][zero[fillCount][1]] = 0;
    return -1;
}

int main(void)
{
    int i, j;
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9; j++)
        {
            scanf("%d", &board[i][j]);
            if (board[i][j] == 0)
            {
                zero[zeroCount][0] = i;
                zero[zeroCount][1] = j;
                zeroCount++;
            }
        }
    }
    Fill(0);
    return 0;
}