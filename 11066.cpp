// URL: https://www.acmicpc.net/problem/11066
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define endl '\n'
#define MAXN 500
#define INF INT_MAX

int minCost[MAXN][MAXN] = {0};
bool visited[MAXN][MAXN] = {0};
int fileSize[MAXN] = {0};

int FindMin(int i, int j)
{
    if (visited[i][j])
        return minCost[i][j];
    visited[i][j] = 1;
    int minimum = INF;
    int sum = 0, esum = 0;
    if (i == j)
        minimum = 0;
    else
    {
        REP(k, i, j + 1)
        {
            sum += fileSize[k];
        }
        REP(k, i, j)
        {
            minimum = min(minimum, FindMin(i, k) + FindMin(k + 1, j) + sum);
        }
    }
    minCost[i][j] = minimum;
    return minimum;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout.setf(ios::fixed);
    // cout.precision(3);
    int T, N;
    cin >> T;
    REP(t, 0, T)
    {
        cin >> N;
        REP(n, 0, N)
        {
            cin >> fileSize[n];
        }
        REP(i, 0, N)
        {
            REP(j, 0, N)
            {
                visited[i][j] = 0;
            }
        }
        cout << FindMin(0, N - 1) << endl;
    }

    return 0;
}