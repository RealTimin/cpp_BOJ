// URL: https://www.acmicpc.net/problem/2294
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define endl '\n'
#define MAXN 20000
#define MAXCOL 10001

int N, K;
int DP[101][MAXCOL] = {0};
bool visited[101][MAXCOL] = {0};

int FindMin(int n, int k, vi &values)
{
    if (visited[n][k] == 1)
        return DP[n][k];
    visited[n][k] = 1;
    if (k == 0)
        return 0;
    if (n == 0)
    {
        DP[n][k] = MAXN;
        return MAXN;
    }
    int v = values[n - 1];
    int kk = k;
    int minCount = MAXN;
    int c = 0;
    minCount = min(minCount, FindMin(n - 1, kk, values) + c);
    while (v <= kk)
    {
        kk -= v;
        c++;
        minCount = min(minCount, FindMin(n - 1, kk, values) + c);
    }
    DP[n][k] = minCount;
    if (minCount == 0)
        cout << "this!!" << n << ' ' << kk << endl;
    return minCount;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout.setf(ios::fixed);
    // cout.precision(3);
    vi values;
    cin >> N >> K;
    int num;
    REP(i, 0, N)
    {
        cin >> num;
        values.push_back(num);
    }
    // sort(values.begin(), values.end(), greater<int>());
    sort(values.begin(), values.end());
    values.erase(unique(values.begin(), values.end()), values.end());

    // for (auto it = values.begin(); it != values.end(); it++)
    // {
    //     cout << *it << ' ';
    // }

    N = values.size();
    FindMin(N, K, values);
    if (DP[N][K] > 10000)
        cout << -1 << endl;
    else
        cout << DP[N][K] << endl;

    // REP(i, 0, N + 1)
    // {
    //     REP(j, 0, K + 1)
    //     {
    //         cout << DP[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    return 0;
}