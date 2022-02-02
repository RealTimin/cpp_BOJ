#include <bits/stdc++.h>
// URL: https://www.acmicpc.net/problem/11725

#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

void findParent(int index, vvi &adj, vi &parent)
{
    int ai;
    for (auto it = adj[index].begin(); it != adj[index].end(); it++)
    {
        ai = (*it) - 1;
        if (parent[ai] == 0)
        {
            parent[ai] = index + 1;
            findParent(ai, adj, parent);
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout.setf(ios::fixed);
    // cout.precision(3);
    int N, a, b;
    cin >> N;
    vvi adj(N);
    vi parent(N, 0);
    // REP(i, 0, N)
    // {
    //     adj.push_back(vi());
    // }
    REP(i, 1, N)
    {
        cin >> a >> b;
        adj[a - 1].push_back(b);
        adj[b - 1].push_back(a);
    }
    parent[0] = 1;
    findParent(0, adj, parent);
    REP(i, 1, N)
    {
        cout << parent[i] << endl;
    }

    return 0;
}