// URL: https://www.acmicpc.net/problem/6086
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define endl '\n'
#define ALPHABET_NUM (int)('z' - 'A' + 1)
#define Z_NUM (int)('Z' - 'A')
#define INF INT_MAX

class Solution {
  public:
    void Solve() {
        Input();
        Output();
    }
    // Data structure
    int N;
    vector<vector<pii>> adj;
    vi parent;
    vi flow;
    vi visited;
    queue<int> q;
    int maxFlow = 0;

  private:
    void Input() {
        cin >> N;
        adj.assign(ALPHABET_NUM, vector<pii>());
        char a, b;
        int an, bn;
        int f;
        bool exist;
        REP(i, 0, N) {
            cin >> a >> b >> f;
            an = (int)(a - 'A');
            bn = (int)(b - 'A');
            exist = false;
            for (auto it = adj[an].begin(); it != adj[an].end(); it++) {
                if ((*it).first == bn) {
                    exist = true;
                    (*it).second += f;
                }
            }
            if (!exist)
                adj[an].push_back({bn, f});

            exist = false;
            for (auto it = adj[bn].begin(); it != adj[bn].end(); it++) {
                if ((*it).first == an) {
                    exist = true;
                    (*it).second += f;
                }
            }
            if (!exist)
                adj[bn].push_back({an, f});
        }
    }

    void Output() {
        bool pathFound = true;
        int node, anode, f, c, p;
        while (pathFound) {

            parent.assign(ALPHABET_NUM, -1);
            visited.assign(ALPHABET_NUM, 0);
            flow.assign(ALPHABET_NUM, 0);
            while (!q.empty())
                q.pop();

            q.push(0);
            parent[0] = 0;
            while (!q.empty()) {
                node = q.front();
                visited[node] = true;
                if (node == Z_NUM)
                    break;

                for (auto it = adj[node].begin(); it != adj[node].end(); it++) {
                    anode = (*it).first;
                    f = (*it).second;
                    if (!visited[anode] && f > 0) {
                        parent[anode] = node;
                        flow[anode] = f;
                        q.push(anode);
                    }
                }
                q.pop();
            }

            if (parent[Z_NUM] == -1)
                pathFound = false;
            else {
                // cancel
                c = INF;
                p = Z_NUM;
                while (p != parent[p]) {
                    c = min(c, flow[p]);
                    p = parent[p];
                }
                maxFlow += c;

                p = Z_NUM;
                while (p != parent[p]) {
                    for (auto it = adj[p].begin(); it != adj[p].end(); it++) {
                        anode = (*it).first;
                        if (anode == parent[p]) {
                            (*it).second += c;
                        }
                    }
                    for (auto it = adj[parent[p]].begin(); it != adj[parent[p]].end(); it++) {
                        anode = (*it).first;
                        if (anode == p) {
                            (*it).second -= c;
                        }
                    }
                    p = parent[p];
                }
            }
        }
        cout << maxFlow;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout.setf(ios::fixed);
    // cout.precision(3);
    Solution solution;
    solution.Solve();
    return 0;
}