#include <bits/stdc++.h>
// URL: https://www.acmicpc.net/problem/11404

#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define endl '\n'
#define INF INT_MAX
using namespace std;

typedef long long ll;
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
    vvi distance;
    int N, M;
    cin >> N >> M;
    REP(i, 0, N)
    {
        vi row(N, INF);
        row[i] = 0;
        distance.push_back(row);
    }
    int s, e, w;
    REP(i, 0, M)
    {
        cin >> s >> e >> w;
        if (distance[--s][--e] > w)
            distance[s][e] = w;
    }
    REP(k, 0, N)
    {
        REP(i, 0, N)
        {
            REP(j, 0, N)
            {
                if (distance[i][k] != INF && distance[k][j] != INF && distance[i][j] > distance[i][k] + distance[k][j])
                    distance[i][j] = distance[i][k] + distance[k][j];
            }
        }
    }

    REP(i, 0, N)
    {
        REP(j, 0, N)
        {
            if (distance[i][j] == INF)
                distance[i][j] = 0;
            cout << distance[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}