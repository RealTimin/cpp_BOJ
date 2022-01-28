#include <iostream>
#include <algorithm>
#include <vector>

#define REP(i, a, b) for (int i = (a); i < (b); i++)

using namespace std;

bool comp(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.first == p2.first)
        return p1.second < p2.second;
    return p1.first < p2.first;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    int x, y;
    vector<pair<int, int>> v;
    REP(i, 0, N)
    {
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }
    sort(v.begin(), v.end(), comp);
    REP(i, 0, N)
    {
        cout << v[i].first << ' ' << v[i].second << '\n';
    }
    return 0;
}