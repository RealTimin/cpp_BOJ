// URL: https://www.acmicpc.net/problem/1520
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define endl '\n'
#define MAXH 20000

int h[502][502] = {0};
int visited[502][502] = {0};
int pathCount[502][502] = {0};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout.setf(ios::fixed);
    // cout.precision(3);
    int D[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int N, M;
    cin >> N >> M;
    REP(i, 1, N + 1)
    {
        REP(j, 1, M + 1)
        {
            cin >> h[i][j];
        }
    }

    REP(i, 0, N + 2)
    {
        h[i][0] = MAXH;
        h[i][M + 1] = MAXH;
    }
    REP(j, 0, M + 2)
    {
        h[0][j] = MAXH;
        h[N + 1][j] = MAXH;
    }

    priority_queue<pair<int, pair<int, int>>> newPos;

    visited[1][1] = true;
    pathCount[1][1] = 1;
    newPos.push({h[1][1], {1, 1}});
    int x, y, ax, ay, hc;
    while (!newPos.empty())
    {
        x = newPos.top().second.first;
        y = newPos.top().second.second;
        hc = h[x][y];
        newPos.pop();
        REP(d, 0, 4)
        {
            ax = x + D[d][0];
            ay = y + D[d][1];
            if (h[ax][ay] > hc)
                pathCount[x][y] += pathCount[ax][ay];
            else if (h[ax][ay] < hc)
            {
                if (!visited[ax][ay])
                {
                    visited[ax][ay] = 1;
                    newPos.push({h[ax][ay], {ax, ay}});
                }
            }
        }
        if (x == N && y == M)
            break;
    }

    cout << pathCount[N][M];

    return 0;
}