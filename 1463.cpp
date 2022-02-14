// #include <stdio.h>

// int main(void)
// {
//     int nums[21][21] = {1, 0};
//     int curRow = 0;
//     int N;
//     int min;
//     int distance;
//     int i;
//     scanf("%d", &N);
//     min = N - nums[0][0] + curRow;
//     while (nums[curRow][0] <= N)
//     {
//         curRow++;
//         for (i = 0; i < curRow; i++)
//         {
//             nums[curRow][i] = nums[curRow - 1][i] * 2;
//         }
//         nums[curRow][curRow] = nums[curRow - 1][curRow - 1] * 3;

//         for (i = 0; i <= curRow; i++)
//         {
//             if(N >= nums[curRow][i])
//             {
//                 distance = N - nums[curRow][i] + curRow;
//                 if (distance < min)
//                 {
//                     min = distance;
//                 }
//             }
//         }
//     }
//     printf("%d", min);
//     return 0;
// }

// #define MAX_NUM 1000000

// #include <stdio.h>

// int minimum[MAX_NUM + 2] = {0};
// int N;

// void Save(int next, int i)
// {
//     if (next <= MAX_NUM)
//     {
//         if (minimum[next] == 0 || (minimum[next] > minimum[i] + 1))
//         {
//             minimum[next] = minimum[i] + 1;
//         }
//     }
// }

// int main(void)
// {
//     int i, next;
//     scanf("%d", &N);
//     for (i = 1; i < N; i++)
//     {
//         next = i + 1;
//         Save(next,i);
//         next = i * 2;
//         Save(next,i);
//         next = i * 3;
//         Save(next,i);
//     }
//     printf("%d", minimum[N]);
//     return 0;
// }

// URL: https://www.acmicpc.net/problem/1463
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define endl '\n'
#define MAXN 1000001

int minCount[MAXN] = {0};
int N;

void FindMin(int index, int prevCount)
{
    if (index > N)
        return;
    if (minCount[index] > prevCount + 1)
    {
        minCount[index] = prevCount + 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout.setf(ios::fixed);
    // cout.precision(3);
    minCount[1] = 0;
    cin >> N;
    REP(i, 2, N + 1)
    {
        minCount[i] = INT_MAX;
    }
    REP(i, 1, N + 1)
    {
        FindMin(i * 2, minCount[i]);
        FindMin(i * 3, minCount[i]);
        FindMin(i + 1, minCount[i]);
    }
    cout << minCount[N];

    return 0;
}