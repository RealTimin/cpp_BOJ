#include <bits/stdc++.h>
// URL: https://www.acmicpc.net/problem/1620

#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define endl '\n'

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout.setf(ios::fixed);
    // cout.precision(3);
    int N, M;
    cin >> N >> M;
    int num;
    int l;
    string name;
    unordered_map<string, int> intDict;
    unordered_map<int, string> strDict;
    REP(i, 0, N)
    {
        cin >> name;
        num = i + 1;
        intDict.insert({name, num});
        strDict.insert({num, name});
    }
    REP(i, 0, M)
    {
        cin >> name;
        stringstream ssInt(name);
        ssInt >> l;
        if (ssInt.fail())
        {
            l = intDict[name];
            cout << intDict[name] << endl;
        }
        else
        {
            cout << strDict[l] << endl;
        }
    }
    return 0;
}