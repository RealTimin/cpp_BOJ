// URL: https://www.acmicpc.net/problem/2623
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define endl '\n'

// topological sort

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout.setf(ios::fixed);
    // cout.precision(3);
    int N, M;
    cin >> N >> M;
    vvi adj(N + 1, vi());
    vi inDegree(N + 1, 0);
    vi visited(N + 1, 0);
    vi result;
    int n1, n2, k;
    REP(i, 0, M)
    {
        cin >> k;
        cin >> n1;
        REP(j, 1, k)
        {
            cin >> n2;
            inDegree[n2]++;
            adj[n1].push_back(n2);
            n1 = n2;
        }
    }

    bool checked = false;
    while (!checked)
    {
        checked = true;
        REP(i, 1, N + 1)
        {
            if (!visited[i] && inDegree[i] == 0)
            {
                visited[i] = 1;
                checked = false;
                for (auto it = adj[i].begin(); it != adj[i].end(); it++)
                    inDegree[(*it)]--;
                result.push_back(i);
            }
        }
    }

    if (result.size() == N)
        for (auto it = result.begin(); it != result.end(); it++)
            cout << (*it) << endl;
    else
        cout << 0 << endl;
    return 0;
}