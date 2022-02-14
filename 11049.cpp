// URL: https://www.acmicpc.net/problem/11066
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define endl '\n'
#define MAXN 502
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
    int mul = fileSize[i] * fileSize[j];
    if (i + 1 == j)
        minimum = 0;
    else
    {
        REP(k, i + 1, j)
        {
            minimum = min(minimum, FindMin(i, k) + FindMin(k, j) + mul * fileSize[k]);
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
    int N, n1, n2;
    cin >> N;
    REP(n, 1, N + 1)
    {
        cin >> fileSize[n - 1] >> fileSize[n];
    }
    cout << FindMin(0, N) << endl;

    return 0;
}