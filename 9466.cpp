// URL: https://www.acmicpc.net/problem/9466
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define endl '\n'
#define MAXN 100001

class Solution
{
public:
    void Solve()
    {
        Input();
    }
    // Data structure
    int T, N, result;
    int adj[MAXN];
    int grouped[MAXN];
    int visited[MAXN];
    stack<int> s;

private:
    void Input()
    {
        cin >> T;
        REP(t, 0, T)
        {
            cin >> N;
            REP(i, 1, N + 1)
            {
                cin >> adj[i];
            }
            REP(i, 1, N + 1)
            {
                visited[i] = 0;
                grouped[i] = 0;
            }
            CheckCycle();
        }
    }

    void CheckCycle()
    {
        REP(i, 1, N + 1)
        {
            if (!visited[i])
                DFS(i);
        }
        result = 0;
        REP(i, 1, N + 1)
        {
            if (grouped[i] == -1)
                result++;
        }
        cout << result << endl;
    }

    void DFS(int index)
    {
        visited[index] = 1;
        s.push(index);
        int ai = adj[index];
        if (visited[ai] == 0)
        {
            DFS(ai);
        }
        else if (visited[ai] == 1 && grouped[ai] == 0) // find cycle -> grouping
        {
            while (s.top() != ai)
            {
                grouped[s.top()] = 1;
                s.pop();
            }
            grouped[s.top()] = 1;
            s.pop();
        }

        // else: (v == 1 && g != 0) -> cannot be group
        while (!s.empty())
        {
            grouped[s.top()] = -1;
            s.pop();
        }
        return;
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