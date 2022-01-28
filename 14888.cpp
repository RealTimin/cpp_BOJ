#include <stdio.h>

#define ADD 0
#define SUBTRACT 1
#define MULTIPLY 2
#define DIVIDE 3

int nums[11]={0};
int N;
int op_cnt[4]={0}; //add, subtract, multiply, divide
int op[10]={0};
int max = 0, min = 0;
int initDone = 0;

int Calculate(void)
{
    int result=nums[0];
    int i;
    for(i=1;i<N; i++)
    {
        switch (op[i-1])
        {
        case ADD:
            result += nums[i];
            break;
        case SUBTRACT:
            result -= nums[i];
            break;
        case MULTIPLY:
            result *= nums[i];
            break;
        case DIVIDE:
            if(result < 0)
            {
                result = -result;
                result /= nums[i];
                result = -result;
            }
            else
            {
                result /= nums[i];
            }
            break;
        default:
            break;
        }
    }
    return result;
}

void SetOp(int k)
{
    if(k == N-1)
    {
        int result = Calculate();
        if(result > max)
            max = result;
        if(result < min)
            min = result;
        if(!initDone)
        {
            max = result;
            min = result;
            initDone = true;
        }
        return;
    }
    int i, j;
    for(i=0; i<4; i++)
    {
        if(op_cnt[i]>0)
        {
            op_cnt[i]--;
            op[k]=i;
            SetOp(k+1);
            op_cnt[i]++;
        }
    }
    return;
}

int main(void)
{
    int i;
    scanf("%d", &N);
    for(i=0;i<N; i++)
    {
        scanf("%d", &nums[i]);
    }
    for(i=0;i<4;i++)
    {
        scanf("%d", &op_cnt[i]);
    }
    SetOp(0);
    printf("%d\n%d", max, min);
    return 0;
}