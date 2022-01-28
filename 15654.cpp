#include <bits/stdc++.h>
// URL: https://www.acmicpc.net/problem/15654

#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define endl '\n'

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     // cout.setf(ios::fixed);
//     // cout.precision(3);
//     int N, M;
//     cin >> N >> M;
//     vi nums(N, 0);
//     vi index(M, 0);
//     REP(i, 0, N)
//     {
//         cin >> nums[i];
//     }
//     sort(nums.begin(), nums.end());
//     REP(i, 0, M)
//     {
//         index[i] = i;
//     }

//     int dif = N - M;
//     int i, pi;
//     while (1)
//     {
//         REP(j, 0, M)
//         {
//             cout << nums[index[j]] << ' ';
//         }
//         cout << endl;
//         for (i = M - 1; i >= 0; i--)
//         {
//             if (index[i] != i + dif)
//                 break;
//         }
//         if (i < 0)
//             break;
//         pi = ++index[i];
//         i++;
//         for (; i < M; i++)
//         {
//             index[i] = ++pi;
//         }
//     }

//     return 0;
// }

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout.setf(ios::fixed);
    // cout.precision(3);
    int N, M;
    cin >> N >> M;
    vi nums(N, 0);
    vi occ(N, 0);
    vi index(M, 0);
    REP(i, 0, N)
    {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    REP(i, 0, M)
    {
        index[i] = i;
        occ[i] = 1;
    }
    int dif = N - M;
    int i, j;
    int lei;
    while (1)
    {
        REP(k, 0, M)
        {
            cout << nums[index[k]] << ' ';
        }
        cout << endl;

        for (i = N - 1; i >= 0; i--)
            if (occ[i] == 0)
            {
                break;
            }
        lei = i;

        for (i = M - 1; i >= 0; i--)
        {
            if (index[i] < lei)
                break;
            else
            {
                lei = index[i] < lei ? lei : index[i];
                occ[index[i]] = 0;
            }
        }
        if (i < 0)
            break;

        occ[index[i]] = 0;
        ++index[i];
        while (occ[index[i]])
        {
            ++index[i];
        }
        occ[index[i]] = 1;
        i++;
        j = 0;
        for (; i < M; i++)
        {
            while (occ[j] && j < M - 1)
                j++;
            index[i] = j;
            occ[j] = 1;
        }
    }
}
