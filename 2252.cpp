// URL: https://www.acmicpc.net/problem/2252
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define endl '\n'

// topological sort
// TODO: make faster

int main() {
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
    int a, b;
    REP(i, 0, M) {
        cin >> a >> b;
        inDegree[b]++;
        adj[a].push_back(b);
    }

    bool checked = false;
    while (!checked) {
        checked = true;
        REP(i, 1, N + 1) {
            if (!visited[i] && inDegree[i] == 0) {
                visited[i] = 1;
                checked = false;
                for (auto it = adj[i].begin(); it != adj[i].end(); it++)
                    inDegree[(*it)]--;
                cout << i << ' ';
            }
        }
    }

    return 0;
}