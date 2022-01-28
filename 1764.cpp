#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = (a); i < (b); i++)

using namespace std;

typedef pair<int, int> pii;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<string> notHeard;
    vi DBJ;
    int DBJcount = 0;
    string name;
    int N, M;
    cin >> N >> M;
    REP(i, 0, N)
    {
        cin >> name;
        notHeard.push_back(name);
    }
    sort(notHeard.begin(), notHeard.end());
    DBJ.assign(notHeard.size(), 0);
    REP(i, 0, M)
    {
        cin >> name;
        auto it = lower_bound(notHeard.begin(), notHeard.end(), name);
        if (it != notHeard.end() && (*it) == name)
        {
            int index = it - notHeard.begin();
            DBJ[index] = 1;
            DBJcount++;
        }
    }
    cout << DBJcount << '\n';
    REP(i, 0, N)
    {
        if (DBJ[i])
        {
            cout << notHeard[i] << '\n';
        }
    }
    return 0;
}