#include <stdio.h>
#define SUM 45

int board[9][9] = {0};
int row_cnt[9] = {0};
int col_cnt[9] = {0};
int box_cnt[3][3] = {0};

void AddZero(int i, int j, int addValue)
{
    row_cnt[i] += addValue;
    col_cnt[j] += addValue;
    box_cnt[i / 3][j / 3] += addValue;
}

void PrintBoard(void)
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    // printf("\n");
}

int main(void)
{
    int i, j, result;
    int k, l;
    int row, col;
    int singleZeroExist = true;
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9; j++)
        {
            scanf("%d", &board[i][j]);
            if (board[i][j] == 0)
            {
                AddZero(i, j, 1);
            }
        }
    }
    
    while (singleZeroExist)
    {
        singleZeroExist = false;
        
        for (i = 0; i < 9; i++)
        {
            if (row_cnt[i] == 1)
            {
                // printf("row checked\n");
                singleZeroExist = true;
                result = SUM;
                for (j = 0; j < 9; j++)
                {
                    result -= board[i][j];
                    if (board[i][j] == 0)
                    {
                        col = j;
                    }
                }
                AddZero(i, col, -1);
                board[i][col] = result;
                // printf("%d %d \n", i, col);
            }

            if (col_cnt[i] == 1)
            {
                // printf("col checked\n");
                singleZeroExist = true;
                result = SUM;
                for (j = 0; j < 9; j++)
                {
                    result -= board[j][i];
                    if (board[j][i] == 0)
                    {
                        row = j;
                    }
                }
                AddZero(row, i, -1);
                board[row][i] = result;
                // printf("%d %d \n", row, i);
            }
        }

        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                if (box_cnt[i][j] == 1)
                {
                    // printf("box checked\n");
                    singleZeroExist = true;
                    result = SUM;
                    for (k = 0; k < 3; k++)
                    {
                        for (l = 0; l < 3; l++)
                        {
                            result -= board[3 * i + k][3 * j + l];
                            if(board[3 * i + k][3 * j + l] == 0)
                            {
                                row = 3 * i + k;
                                col = 3 * j + l;
                            }
                        }
                    }
                    AddZero(row, col, -1);
                    board[row][col] = result;
                    // printf("%d %d \n", row, col);
                }
            }
        }
    }

    PrintBoard();
    return 0;
}