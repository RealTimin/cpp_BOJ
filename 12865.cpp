// URL: https://www.acmicpc.net/problem/12865
// REF: https://gsmesie692.tistory.com/113
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define endl '\n'

int P[101][100001];
int visited[101][100001];
int stuff[101][2]; // weight, value
int N, W;

int Solve(int stuffCount, int weight)
{
    if (visited[stuffCount][weight])
        return P[stuffCount][weight];
    visited[stuffCount][weight] = 1;
    if (stuffCount == 0)
        return 0;
    int w = stuff[stuffCount][0];
    int v = stuff[stuffCount][1];
    if (weight < w)
    {
        P[stuffCount][weight] = max(P[stuffCount][weight], Solve(stuffCount - 1, weight));
    }
    else
    {
        P[stuffCount][weight] = max(max(v + Solve(stuffCount - 1, weight - w), Solve(stuffCount - 1, weight)), P[stuffCount][weight]);
    }
    return P[stuffCount][weight];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout.setf(ios::fixed);
    // cout.precision(3);
    cin >> N >> W;
    REP(i, 1, N + 1)
    {
        cin >> stuff[i][0];
        cin >> stuff[i][1];
    }
    Solve(N, W);
    cout << P[N][W];

    return 0;
}