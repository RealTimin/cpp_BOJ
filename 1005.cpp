// URL: https://www.acmicpc.net/problem/1005
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define endl '\n'

// topological sort advanced
// maybe not topological sort, but DFS

class Solution
{
public:
    void Solve()
    {
        Input();
    }
    // Data structure
    int T, N, M, W;
    int a, b;
    int result;
    vvi adj;
    vi bulidTime;
    vi visited;
    vi maxTimeSave;

private:
    void Input()
    {
        cin >> T;
        REP(t, 0, T)
        {
            cin >> N >> M;
            adj.assign(N, vi());
            bulidTime.assign(N, 0);
            visited.assign(N, 0);
            maxTimeSave.assign(N, 0);
            REP(i, 0, N)
            {
                cin >> bulidTime[i];
            }
            REP(i, 0, M)
            {
                cin >> a >> b;
                adj[b - 1].push_back(a - 1);
            }
            cin >> W;
            cout << DFS(W - 1) << endl;
        }
    }

    int DFS(int index)
    {
        if (visited[index])
            return maxTimeSave[index];
        int maxTime = 0;
        visited[index] = 1;
        for (auto it = adj[index].begin(); it != adj[index].end(); it++)
        {
            maxTime = max(maxTime, DFS(*it));
        }
        maxTimeSave[index] = maxTime + bulidTime[index];
        return maxTimeSave[index];
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout.setf(ios::fixed);
    // cout.precision(3);
    Solution solution;
    solution.Solve();
    return 0;
}