// URL: https://www.acmicpc.net/problem/2637
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout.setf(ios::fixed);
    // cout.precision(3);
    int N, M;
    cin >> N >> M;
    vector<vector<pii>> adj(N, vector<pii>());
    vi inDegree(N, 0);
    vi visited(N, 0);
    vi total(N, 0);
    int a, b, c;
    REP(i, 0, M)
    {
        cin >> a >> b >> c;
        adj[a - 1].push_back({b - 1, c});
        inDegree[b - 1]++;
    }
    bool checked = false;
    total[N - 1] = 1;
    while (!checked)
    {
        checked = true;
        REP(i, 0, N)
        {
            if (!visited[i] && inDegree[i] == 0)
            {
                visited[i] = true;
                checked = false;
                if (adj[i].empty())
                    continue;
                for (auto it = adj[i].begin(); it != adj[i].end(); it++)
                {
                    b = (*it).first;
                    c = (*it).second;
                    total[b] += total[i] * c;
                    inDegree[b]--;
                }
                total[i] = 0;
                adj[i].clear();
            }
        }
    }
    REP(i, 0, N)
    {
        if (total[i] != 0)
            cout << (i + 1) << ' ' << total[i] << endl;
    }

    return 0;
}