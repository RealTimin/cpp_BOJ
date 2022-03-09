// URL: https://www.acmicpc.net/problem/24526
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define endl '\n'

class Solution {
  public:
    void Solve() {
        Input();
        Output();
    }
    // Data structure
    int N, M;
    vvi adj;
    vi visited;
    vi finished;
    vi isValid;
    vi s;

  private:
    void Input() {
        cin >> N >> M;
        adj.assign(N, vi());
        visited.assign(N, 0);
        finished.assign(N, 0);
        isValid.assign(N, -1);
        int n1, n2;
        REP(m, 0, M) {
            cin >> n1 >> n2;
            n1--, n2--;
            // auto it = find(adj[n1].begin(), adj[n1].end(), n2);
            // if (it == adj[n1].end()) {
            //     adj[n1].push_back(n2);
            // }
            adj[n1].push_back(n2);
        }
    }

    void Output() {
        REP(i, 0, N) {
            if (!visited[i]) {
                s.clear();
                DFS(i);
            }
        }
        int count = 0;
        REP(i, 0, N) {
            if (isValid[i] == 1)
                count++;
        }
        cout << count << endl;
    }

    void MakeStackInvalid() {
        for (auto it = s.rbegin(); it != s.rend(); it++) {
            if (isValid[(*it)] == -1)
                isValid[(*it)] = 0;
            else
                break;
        }
    }

    void DFS(int index) {
        visited[index] = 1;
        s.push_back(index);
        int ai;
        for (auto it = adj[index].begin(); it != adj[index].end(); it++) {
            ai = (*it);
            if (visited[ai]) {
                if (!finished[ai]) {
                    // cycle detected
                    // all people in 's' are invalid
                    MakeStackInvalid();
                } else if (isValid[ai] == 0) {
                    // invalid
                    MakeStackInvalid();
                } else {
                    // valid
                    // do nothing
                }
            } else {
                // unvisited -> dfs
                DFS(ai);
            }
        }

        if (isValid[index] == -1) {
            isValid[index] = 1;
        }
        s.pop_back();
        finished[index] = 1;
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