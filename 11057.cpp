// URL: https://www.acmicpc.net/problem/11057
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define endl '\n'
#define MOD 10007
#define MAXN 1002

int dp[10][MAXN] = {0};
int N;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout.setf(ios::fixed);
    // cout.precision(3);
    cin >> N;
    REP(i, 0, 10)
    {
        dp[i][1] = 1;
    }
    int sum;
    REP(j, 2, N + 2)
    {
        sum = 0;
        REP(i, 0, 10)
        {
            sum += dp[i][j - 1];
            sum %= MOD;
            dp[i][j] = sum;
        }
    }
    cout << dp[9][N + 1];
    return 0;
}