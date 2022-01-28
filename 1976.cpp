#include <bits/stdc++.h>
// URL: https://www.acmicpc.net/problem/1976

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

int main()
{
    // NOTE:
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, M;
    bool adj;
    bool sameSet;
    bool possibleTrip;
    int city;
    int prevCity;
    cin >> N >> M;
    UnionFind unionFind(N);

    REP(i, 0, N)
    {
        REP(j, 0, N)
        {
            cin >> adj;
            if (adj)
                unionFind.Union(i, j);
        }
    }

    possibleTrip = true;
    cin >> prevCity;
    REP(i, 1, M)
    {
        cin >> city;
        sameSet = (unionFind.Find(city - 1) == unionFind.Find(prevCity - 1));
        if (!sameSet)
            possibleTrip = false;
        prevCity = city;
    

    if (possibleTrip)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}