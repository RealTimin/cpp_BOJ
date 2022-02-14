// URL: https://www.acmicpc.net/problem/2482
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define endl '\n'
#define MAXN 1001
#define MOD 1000000003

int L[MAXN][MAXN] = {0};
bool visited[MAXN][MAXN] = {0};
int N, K;

int FindL(int n, int k)
{
    if (visited[n][k])
        return L[n][k];
    visited[n][k] = 1;
    int lval;
    if (k == 0)
    {
        lval = 1; // (n,0)
    }
    else if (n == 1)
    {
        lval = 1; // (1,1)
    }
    else if (n <= 2 * k - 2)
    {
        lval = 0; // impossible
    }
    else
    {
        lval = (FindL(n - 2, k - 1) + FindL(n - 1, k)) % MOD;
    }
    L[n][k] = lval;
    return lval;
}

// C(n,k) = L(n-3,k-1) + L(n-1,k)
// L(n,k) = n if (k == 1), 0 if (n <= 2k-2), else L(n-2,k-1) + L(n-1,k)
// TODO:
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout.setf(ios::fixed);
    // cout.precision(3);
    cin >> N >> K;
    int result = (FindL(N - 3, K - 1) + FindL(N - 1, K)) % MOD;
    cout << result;

    return 0;
}