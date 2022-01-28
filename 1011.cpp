#include <stdio.h>

int main(void)
{
    int T;
    int x, y;
    int length, count, dist;
    unsigned long long dist_sum;
    int i, j;

    // cin >> T;
    scanf("%d", &T);
    int *array = new int[T];
    for (i = 0; i < T; i++)
    {
        // cin >> x;
        // cin >> y;
        scanf("%d %d", &x, &y);
        length = y - x;
        dist = 1, dist_sum = 0, count = 0;
        while (dist_sum < length)
        {
            count++;
            dist_sum += dist;
            if(dist_sum < 0)
                break;
            if (count % 2 == 0) //__builtin_ctz(count)  count % 2 == 0
            {
                dist++;
            }
        }
        array[i] = count;
    }
    for (i = 0; i < T; i++)
    {
        // cout << count << endl;
        printf("%d\n", array[i]);
    }

    return 0;
}

// #include <stdio.h>

// int main(void)
// {
//     unsigned long long square[50000] = {0};
//     int T;
//     int x, y;
//     int length, count, n;
//     int i, j;

//     scanf("%d", &T);
//     int *array = new int[T];
//     for (i = 0; i < T; i++)
//     {
//         scanf("%d %d", &x, &y);
//         length = y - x;
//         n = 1, count = 0;
//         while(1)
//         {
//             if(square[n] == 0)
//             {
//                 if(n * n > 0)
//                 {
//                     square[n] = n * n;

//                 }
//                 else
//                 {
//                     break;
//                 }
//             }
//             if(square[n] >= length)
//             {
//                 break;
//             }
//             n++;
//         }
//         if (length <= n * (n - 1))
//         {
//             count = 2 * n - 2;
//         }
//         else
//         {
//             count = 2 * n - 1;
//         }
//         array[i] = count;
//     }
//     for (i = 0; i < T; i++)
//     {
//         printf("%d\n", array[i]);
//     }

//     return 0;
// }