// URL: https://www.acmicpc.net/problem/2150
#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

bool comp(vi &a, vi &b)
{
    return a[0] < b[0];
}

class Solution
{
public:
    void Solve()
    {
        Input();
        Tarjan();
    }
    // Data structure
    int V, E;
    vvi adj;
    vi visited;
    int visitCount = 0;
    vi sccID;
    int sccCount = 0;
    vvi SCCs;
    vi SCC;
    stack<int> s;

private:
    void Input()
    {
        cin >> V >> E;
        adj.assign(V, vi());
        visited.assign(V, -1);
        sccID.assign(V, -1);
        int A, B;
        REP(i, 0, E)
        {
            cin >> A >> B;
            adj[A - 1].push_back(B - 1);
        }
    }

    void Tarjan()
    {
        REP(i, 0, V)
        {
            if (visited[i] == -1)
            {
                DFS(i);
            }
        }
        sort(SCCs.begin(), SCCs.end(), comp);
        cout << sccCount << endl;
        for (auto it = SCCs.begin(); it != SCCs.end(); it++)
        {
            for (auto i = (*it).begin(); i != (*it).end(); i++)
            {
                cout << (*i) + 1 << ' ';
            }
            cout << -1 << endl;
        }
        return;
    }

    int DFS(int index)
    {
        visited[index] = visitCount;
        int low = visitCount++;
        s.push(index);
        int ai, ti;
        for (auto it = adj[index].begin(); it != adj[index].end(); it++)
        {
            ai = (*it);
            if (visited[ai] == -1)
            {
                low = min(low, DFS(ai));
            }
            else if (sccID[ai] == -1)
            {
                low = min(low, visited[ai]);
            }
        }
        if (low == visited[index])
        {
            SCC.clear();
            // make scc
            while (!s.empty())
            {
                ti = s.top();
                sccID[ti] = sccCount;
                SCC.push_back(ti);
                s.pop();
                if (ti == index)
                    break;
            }
            sccCount++;
            sort(SCC.begin(), SCC.end());
            SCCs.push_back(SCC);
        }
        return low;
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