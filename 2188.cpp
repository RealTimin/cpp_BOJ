// URL: https://www.acmicpc.net/problem/2188
#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

class Solution
{
public:
    void Solve()
    {
        Input();
        FindMaxFlow();
    }
    // Data structure
    int N, M;
    vector<vector<pii>> adj;
    vi p;
    int maxFlow = 0;
    int size;

private:
    void Input()
    {
        cin >> N >> M;
        size = N + M + 2;
        adj.assign(size, vector<pii>()); // source, N mans, M jobs, sink
        InitP();
        REP(i, 0, N)
        {
            adj[0].push_back({i + 1, 1});
            adj[i + 1].push_back({0, 0});
        }
        REP(i, 0, M)
        {
            adj[size - 1].push_back({N + 1 + i, 0});
            adj[N + 1 + i].push_back({size - 1, 1});
        }
        int c, job, man;
        REP(i, 0, N)
        {
            man = i + 1;
            cin >> c;
            REP(j, 0, c)
            {
                cin >> job;
                job += N;
                adj[man].push_back({job, 1});
                adj[job].push_back({man, 0});
            }
        }
    }

    void FindMaxFlow()
    {
        bool findPath = true;
        int index;
        while (findPath)
        {
            InitP();
            DFS(0);
            if (p[size - 1] == -1)
                findPath = false;
            else
            {
                maxFlow++;
                index = size - 1;
                while (index != p[index])
                {
                    Cancel(index, p[index]);
                    index = p[index];
                }
            }
        }
        cout << maxFlow;
    }

    void InitP()
    {
        p.assign(size, -1);
        p[0] = 0;
    }

    void Cancel(int i, int pi)
    {
        // pi -> i path cancel
        for (auto it = adj[i].begin(); it != adj[i].end(); it++)
        {
            if ((*it).first == pi)
                (*it).second = 1;
        }
        for (auto it = adj[pi].begin(); it != adj[pi].end(); it++)
        {
            if ((*it).first == i)
                (*it).second = 0;
        }
    }

    void DFS(int index)
    {
        if (index == size - 1)
            return;
        int ai;
        for (auto it = adj[index].begin(); it != adj[index].end(); it++)
        {
            ai = (*it).first;
            if (p[ai] == -1 && (*it).second == 1)
            {
                p[ai] = index;
                DFS(ai);
            }
        }
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