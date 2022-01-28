#include <stdio.h>

int first_drink_max[10002];
int second_drink_max[10002];
int not_drink_max[10002];
int N;

int max(int a, int b)
{
    return a > b ? a : b;
}

int main(void)
{
    int i, quan;
    scanf("%d", &N);
    scanf("%d", &quan);
    first_drink_max[1] = quan;
    second_drink_max[1] = quan;
    for (i = 2; i <= N; i++)
    {
        scanf("%d", &quan);
        first_drink_max[i] = not_drink_max[i - 1] + quan;
        second_drink_max[i] = first_drink_max[i - 1] + quan;
        not_drink_max[i] = max(first_drink_max[i - 1], max(second_drink_max[i - 1], not_drink_max[i - 1]));
    }
    printf("%d", max(first_drink_max[i - 1], max(second_drink_max[i - 1], not_drink_max[i - 1])));
    return 0;
}


//
// read write로 열었는데 read only 로 못바꾸나
// 이게 나야
// 