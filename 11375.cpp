// URL: https://www.acmicpc.net/problem/11375
// TODO: Hofcroft-Karp
#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

// class Solution
// {
// public:
//     void Solve()
//     {
//         Input();
//         FindMaxFlow();
//     }
//     // Data structure
//     int N, M;
//     vector<vector<pii>> adj;
//     queue<int> q;
//     vi p;
//     int maxFlow = 0;
//     int size;

// private:
//     void Input()
//     {
//         cin >> N >> M;
//         size = N + M + 2;
//         adj.assign(size, vector<pii>()); // source, N mans, M jobs, sink
//         // InitPQ();
//         REP(i, 0, N)
//         {
//             adj[0].push_back({i + 1, 1});
//             adj[i + 1].push_back({0, 0});
//         }
//         REP(i, 0, M)
//         {
//             adj[size - 1].push_back({N + 1 + i, 0});
//             adj[N + 1 + i].push_back({size - 1, 1});
//         }
//         int c, job, man;
//         REP(i, 0, N)
//         {
//             man = i + 1;
//             cin >> c;
//             REP(j, 0, c)
//             {
//                 cin >> job;
//                 job += N;
//                 adj[man].push_back({job, 1});
//                 adj[job].push_back({man, 0});
//             }
//         }
//     }

//     void FindMaxFlow()
//     {
//         bool findPath = true;
//         int index;
//         while (findPath)
//         {
//             BFS();
//             if (p[size - 1] == -1)
//                 findPath = false;
//             else
//             {
//                 maxFlow++;
//                 index = size - 1;
//                 while (index != p[index])
//                 {
//                     Cancel(index, p[index]);
//                     index = p[index];
//                 }
//             }
//         }
//         cout << maxFlow;
//     }

//     void InitPQ()
//     {
//         p.assign(size, -1);
//         p[0] = 0;
//         while (!q.empty())
//             q.pop();
//         q.push(0);
//     }

//     void Cancel(int i, int pi)
//     {
//         // pi -> i path cancel
//         for (auto it = adj[i].begin(); it != adj[i].end(); it++)
//         {
//             if ((*it).first == pi)
//                 (*it).second = 1;
//         }
//         for (auto it = adj[pi].begin(); it != adj[pi].end(); it++)
//         {
//             if ((*it).first == i)
//                 (*it).second = 0;
//         }
//     }

//     void BFS()
//     {
//         InitPQ();
//         int ai, index;
//         while (!q.empty())
//         {
//             index = q.front();
//             if (index == size - 1)
//                 break;
//             for (auto it = adj[index].begin(); it != adj[index].end(); it++)
//             {
//                 ai = (*it).first;
//                 if (p[ai] == -1 && (*it).second == 1)
//                 {
//                     p[ai] = index;
//                     q.push(ai);
//                 }
//             }
//             q.pop();
//         }
//     }
// };

// memory error <- infinite DFS
#define MAX 1050
int man[MAX] = {0};
int job[MAX] = {0};
int visited[MAX] = {0};

bool DFS(vvi &adj, int job_index)
{
    visited[job_index] = 1;
    int i = job[job_index];
    int ai;
    bool pathFound = false;
    for (auto it = adj[i].begin(); it != adj[i].end(); it++)
    {
        ai = (*it);
        if (visited[ai] == 0)
        {
            if (job[ai] == 0)
                pathFound = true;
            else
                pathFound = DFS(adj, ai);

            if (pathFound)
            {
                man[i] = ai;
                job[ai] = i;
                break;
            }
        }
    }
    return pathFound;
}

int main()
{
    int N, M;
    int maxFlow = 0;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout.setf(ios::fixed);
    // cout.precision(3);
    // Solution solution;
    // solution.Solve();
    cin >> N >> M;
    vvi adj(N + 1, vi()); // source, N mans, M jobs, sink
    int c, jo, m;
    REP(i, 0, N)
    {
        m = i + 1;
        cin >> c;
        REP(j, 0, c)
        {
            cin >> jo;
            adj[m].push_back(jo);
        }
    }

    auto it = adj[0].begin();
    int ai;
    bool pathFound;
    REP(i, 1, N + 1)
    {
        for (it = adj[i].begin(); it != adj[i].end(); it++)
        {
            ai = (*it);
            if (job[ai] == 0)
            {
                maxFlow++;
                man[i] = ai;
                job[ai] = i;
                break;
            }
        }
    }

    REP(i, 1, N + 1)
    {
        if (man[i] == 0)
        {
            for (it = adj[i].begin(); it != adj[i].end(); it++)
            {
                ai = (*it);
                // memset(visited, 0, sizeof(visited));
                REP(j, 0, MAX)
                {
                    visited[j] = 0;
                }
                pathFound = DFS(adj, ai);
                if (pathFound)
                {
                    maxFlow++;
                    man[i] = ai;
                    job[ai] = i;
                    break;
                }
            }
        }
    }
    cout << maxFlow;
    return 0;
}