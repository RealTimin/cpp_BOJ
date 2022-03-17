// URL: https://www.acmicpc.net/problem/2207
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define endl '\n'
#define ALL(v) (v).begin(), (v).end()
#define FOREACH(it, v) for (__typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

class Solution {
  public:
    void Solve() {
        Input();
        Output();
    }
    // Data structure
    int N, M;
    vvi adj; // (1, 2, ..., N, -N, ..., -2, -1)---> 2N vertices
    vi sccNum;
    vvi sccs;
    int sccCount;
    int visitCount;
    vi visited;
    vi finished;
    vi low;
    stack<int> s;
    vi values;

  private:
    void Input() {
        // cin >> N >> M;
        cin >> M >> N;
        // initialization
        adj.assign(2 * N, vi());

        // input
        int x, y, nx, ny;
        REP(i, 0, M) {
            cin >> x >> y;
            if (x < 0) {
                nx = -x - 1;
                x = 2 * N + x;
            } else {
                nx = 2 * N - x;
                x--;
            }
            if (y < 0) {
                ny = -y - 1;
                y = 2 * N + y;
            } else {
                ny = 2 * N - y;
                y--;
            }
            adj[nx].push_back(y);
            adj[ny].push_back(x);
        }
    }

    void Tarjan() {
        sccNum.assign(2 * N, -1);
        visited.assign(2 * N, -1);
        low.assign(2 * N, -1);
        sccCount = 0, visitCount = 0;
        REP(i, 0, 2 * N) {
            if (visited[i] == -1) {
                while (!s.empty())
                    s.pop();
                DFS(i);
            }
        }
    }

    int DFS(int id) {
        s.push(id);
        visited[id] = visitCount;
        visitCount++;
        low[id] = visited[id];
        int ai;
        FOREACH(it, adj[id]) {
            ai = *it;
            if (visited[ai] == -1) {
                low[id] = min(low[id], DFS(ai));
            } else if (sccNum[ai] == -1) { // ★★★ if not contained in some scc
                // update low
                low[id] = min(low[id], visited[ai]);
            } else {
                // do nothing
            }
        }
        // find scc from stack
        if (low[id] == visited[id]) {
            int temp;
            vi scc;
            while (!s.empty()) {
                temp = s.top();
                scc.push_back(temp);
                sccNum[temp] = sccCount;
                s.pop();
                if (temp == id)
                    break;
            }
            sccs.push_back(scc);
            sccCount++;
        }
        return low[id];
    }

    void Output() {
        Tarjan();
        int ni;
        bool possible = true;
        REP(i, 0, N) {
            ni = 2 * N - 1 - i;
            if (sccNum[i] == sccNum[ni]) {
                possible = false;
                break;
            }
        }

        if (possible)
            cout << "^_^";
        else
            cout << "OTL";
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