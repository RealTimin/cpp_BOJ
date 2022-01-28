#define __max(a, b) (((a) > (b)) ? (a) : (b))

#include <stdio.h>
#include <math.h>

int main(void)
{
    int T, i;
    int x_1, y_1, r_1, x_2, y_2, r_2;
    float distance;
    float max_num, else_sum;
    int count;
    scanf("%d", &T);
    for (i = 0; i < T; i++)
    {
        scanf("%d %d %d %d %d %d", &x_1, &y_1, &r_1, &x_2, &y_2, &r_2);

        distance = sqrt((x_1 - x_2) * (x_1 - x_2) + (y_1 - y_2) * (y_1 - y_2));

        if (distance == (float)0)
        {
            if (r_1 == r_2)
                count = -1;
            else
                count = 0;
        }
        else
        {
            max_num = __max(distance, __max(r_1, r_2));
            else_sum = distance + r_1 + r_2 - max_num;
            if (max_num > else_sum)
            {
                count = 0;
            }
            else if (max_num == else_sum)
            {
                count = 1;
            }
            else
            {
                count = 2;
            }
        }
        printf("%d\n", count);
    }
    return 0;
}