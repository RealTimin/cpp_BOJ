#include <bits/stdc++.h>
// URL: https://www.acmicpc.net/problem/1774

#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define endl '\n'

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

class UnionFind
{
public:
    UnionFind() : size(0){};
    UnionFind(int _size)
    {
        size = _size;
        parent.assign(size, 0);
        rank.assign(size, 0);
        MakeAllSet();
    }
    int GetSize() { return size; }
    void Resize(int _size)
    {
        parent.resize(_size);
        rank.resize(_size);
        REP(i, size, _size)
        {
            MakeSet(i);
        }
    }

    void MakeAllSet();
    void MakeSet(int x);
    int Find(int x);
    void Union(int x, int y);

private:
    int size;
    vector<int> parent;
    vector<int> rank;
};

void UnionFind::MakeAllSet()
{
    REP(i, 0, size)
    {
        MakeSet(i);
    }
}
void UnionFind::MakeSet(int x)
{
    if (x < 0 || x >= size)
        return;
    parent[x] = x;
    rank[x] = 0;
}
int UnionFind::Find(int x)
{
    if (x < 0 || x >= size)
        return -1;
    if (parent[x] == x)
        return x;
    parent[x] = Find(parent[x]);
    return parent[x];
}
void UnionFind::Union(int x, int y)
{
    if (x < 0 || x >= size)
        return;
    if (y < 0 || y >= size)
        return;
    int px = Find(x);
    int py = Find(y);
    if (px == py)
        return;
    int si = px > py ? py : px;
    int bi = px > py ? px : py;
    if (rank[si] < rank[bi])
    {
        parent[si] = bi;
    }
    else
    {
        parent[bi] = si;
        if (rank[si] == rank[bi])
            rank[si]++;
    }
}

double dist(long long x1, long long y1, long long x2, long long y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(2);
    int N, M;
    cin >> N >> M;
    vector<pii> pos;
    vector<pair<double, pii>> edges;
    UnionFind uf(N);
    int x, y;
    int n1, n2;
    int size = 0;
    double weight;
    double result = 0;
    REP(i, 0, N)
    {
        cin >> x >> y;
        for (int i = 0; i < size; i++)
        {
            weight = dist(pos[i].first, pos[i].second, x, y);
            edges.push_back({weight, {i, size}});
        }
        size++;
        pos.push_back({x, y});
    }

    sort(edges.begin(), edges.end());

    REP(i, 0, M)
    {
        cin >> n1 >> n2;
        // add edges
        uf.Union(n1 - 1, n2 - 1);
        // result += dist(pos[n1 - 1].first, pos[n1 - 1].second, pos[n2 - 1].first, pos[n2 - 1].second);
    }

    // kruskal
    int i = 0;
    int E = edges.size();
    // REP(k, M, N - 1)
    // {
    while (i < E)
    {
        n1 = edges[i].second.first;
        n2 = edges[i].second.second;
        if (uf.Find(n1) != uf.Find(n2))
        {
            // add edges
            uf.Union(n1, n2);
            result += edges[i].first;
            // break;
        }
        i++;
    }
    // }

    // int result_int = result * 100;
    // result = result_int / 100;
    cout << result;

    return 0;
}