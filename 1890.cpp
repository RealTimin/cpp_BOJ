// URL: https://www.acmicpc.net/problem/1890
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define endl '\n'

int board[101][101];
ll pathCount[101][101];
int N;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout.setf(ios::fixed);
    // cout.precision(3);
    cin >> N;

    REP(i, 1, N + 1)
    REP(j, 1, N + 1)
    cin >> board[i][j];

    int ni, nj, p;
    pathCount[1][1] = 1;

    REP(i, 1, N + 1)
    {
        REP(j, 1, N + 1)
        {
            p = board[i][j];
            if (p == 0)
                continue;
            ni = i + p;
            nj = j + p;
            if (ni <= N)
                pathCount[ni][j] += pathCount[i][j];
            if (nj <= N)
                pathCount[i][nj] += pathCount[i][j];
        }
    }

    cout << pathCount[N][N];

    return 0;
}