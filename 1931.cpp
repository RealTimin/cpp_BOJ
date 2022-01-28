#include <bits/stdc++.h>
// URL: https://www.acmicpc.net/problem/1931

#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define endl '\n'

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout.setf(ios::fixed);
    // cout.precision(3);
    vi minEndTimeWithWidth = {0};
    int maxSize = 0;
    bool prevIncrease, nextIncrease;
    vector<pii> sch; // sort with low st, low et
    int N;
    int st, et;
    cin >> N;
    REP(i, 0, N)
    {
        cin >> st >> et;
        sch.push_back({st, et});
    }
    sort(sch.begin(), sch.end());
    REP(i, 0, N)
    {
        auto it = upper_bound(minEndTimeWithWidth.begin(), minEndTimeWithWidth.end(), sch[i].first);
        if (it == minEndTimeWithWidth.end())
        {
            minEndTimeWithWidth.push_back(sch[i].second);
        }
        else
        {
            if (sch[i].second < (*it))
                (*it) = sch[i].second;
        }
    }
    cout << minEndTimeWithWidth.size() - 1;
    return 0;
}

// timeout.
// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     // cout.setf(ios::fixed);
//     // cout.precision(3);
//     vi minEndTimeWithWidth = {0};
//     int maxSize = 0;
//     bool prevIncrease, nextIncrease;
//     vector<pii> sch; // sort with low st, low et
//     int N;
//     int st, et;
//     cin >> N;
//     REP(i, 0, N)
//     {
//         cin >> st >> et;
//         sch.push_back({st, et});
//     }
//     sort(sch.begin(), sch.end());
//     REP(i, 0, N)
//     {
//         prevIncrease = false;
//         REP(j, 0, maxSize + 1)
//         {
//             // (sch[i].first != sch[i].second || (sch[i].first == sch[i].second && !increaseSize)) &&;
//             if (minEndTimeWithWidth[j] <= sch[i].first)
//             {
//                 nextIncrease = true;
//             }
//             else
//                 nextIncrease = false;
//             if (prevIncrease)
//             {
//                 if (minEndTimeWithWidth[j] > sch[i].second)
//                     minEndTimeWithWidth[j] = sch[i].second;
//             }
//             prevIncrease = nextIncrease;
//         }
//         if (prevIncrease)
//         {
//             minEndTimeWithWidth.push_back(sch[i].second);
//             maxSize++;
//         }
//     }

//     cout << maxSize;

//     return 0;
// }