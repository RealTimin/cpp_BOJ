#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

#define REP(i, a, b) for (int i = (a); i < (b); i++)

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    map<int, int> dict;
    int N, M;
    int num;
    cin >> N;
    REP(i, 0, N)
    {
        cin >> num;
        auto [it, suc] = dict.insert(make_pair(num, 1));    // TODO: decleration outside REP -> reduce time
        if (!suc)
        {
            (*it).second += 1;
        }
    }
    cin >> M;
    auto eit = dict.end();
    REP(i, 0, M)
    {
        cin >> num;
        auto it = dict.find(num);
        if (it == eit)
        {
            cout << 0 << ' ';
        }
        else
        {
            cout << (*it).second << ' ';
        }
    }

    return 0;
}