#include <bits/stdc++.h>
// URL: https://www.acmicpc.net/problem/11725

#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

void findDistance(int index, vector<vector<pii>> &adj, vi &distance)
{
    int ai, w;
    for (auto it = adj[index].begin(); it != adj[index].end(); it++)
    {
        ai = (*it).first;
        w = (*it).second;
        if (distance[ai] == -1)
        {
            distance[ai] = distance[index] + w;
            findDistance(ai, adj, distance);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout.setf(ios::fixed);
    // cout.precision(3);
    int N, a, b, w;
    cin >> N;
    // vvi adj(N);
    vector<vector<pii>> adj(N);
    vi distance(N, -1);
    REP(i, 1, N)
    {
        cin >> a >> b >> w;
        adj[a - 1].push_back({b - 1, w});
        adj[b - 1].push_back({a - 1, w});
    }
    distance[0] = 0;
    findDistance(0, adj, distance);
    int max = -1;
    int maxi;
    REP(i, 0, N)
    {
        if (max < distance[i])
        {
            max = distance[i];
            maxi = i;
        }
        distance[i] = -1;
    }
    distance[maxi] = 0;
    findDistance(maxi, adj, distance);
    max = -1;
    REP(i, 0, N)
    {
        if (max < distance[i])
            max = distance[i];
    }
    cout << max;
    return 0;
}