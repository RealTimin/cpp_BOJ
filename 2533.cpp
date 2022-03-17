// URL: https://www.acmicpc.net/problem/2533
// My solution: greedy
// Intention: dp in tree (If parent node is EA, decide which child is EA. If parent node is not EA, all chidren nodes are EA. )
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
    int N;
    vvi adj;
    priority_queue<pii, vector<pii>, greater<pii>> pq; // <neighbor count, index>
    vi visited;
    vi nc;
    int cnt = 0;

  private:
    void Input() {
        int n1, n2;
        cin >> N;
        adj.assign(N, {});
        visited.assign(N, 0);
        nc.assign(N, 0);

        REP(i, 1, N) {
            cin >> n1 >> n2;
            n1--, n2--;
            adj[n1].push_back(n2);
            adj[n2].push_back(n1);
        }

        REP(i, 0, N) {
            pq.push({adj[i].size(), i});
            nc[i] = adj[i].size();
        }
    }

    void Output() {
        bool check = false;
        int ai, aai, index;
        while (!pq.empty()) {
            index = pq.top().second;
            pq.pop();
            if (visited[index])
                continue;
            visited[index] = 1;
            FOREACH(it, adj[index]) {
                ai = (*it);
                if (!visited[ai]) {
                    cnt++;
                    visited[ai] = 1;
                    FOREACH(ait, adj[ai]) {
                        aai = (*ait);
                        if (!visited[aai]) {
                            nc[aai]--;
                            pq.push({nc[aai], aai});
                        }
                    }
                }
            }
        }
        cout << cnt;
    }
};

// class Solution {
//   public:
//     void Solve() {
//         Input();
//         Output();
//     }
//     // Data structure
//     int N;
//     vvi adj;
//     int c = 0;

//   private:
//     void Input() {
//         int n1, n2;
//         cin >> N;
//         adj.assign(N + 1, {});
//         REP(i, 1, N) {
//             cin >> n1 >> n2;
//             adj[n1].push_back(n2);
//             adj[n2].push_back(n1);
//         }
//     }

//     void Output() {
//         bool check = false;
//         int ai, index;
//         while (!check) {
//             check = true;
//             REP(i, 1, N + 1) {
//                 if (adj[i].size() == 1) {
//                     c++;
//                     ai = adj[i][0];
//                     for (auto it = adj[ai].begin(); it != adj[ai].end(); it++) {
//                         index = (*it);
//                         auto f = find(adj[index].begin(), adj[index].end(), ai);
//                         adj[index].erase(f, f + 1);
//                     }
//                     adj[ai].clear();
//                     check = false;
//                 }
//             }
//         }
//         cout << c;
//     }
// };

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