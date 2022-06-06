// URL: https://www.acmicpc.net/problem/14425
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define endl '\n'
#define ALL(v) (v).begin(), (v).end()
#define FOREACH(it, v) for (__typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout.setf(ios::fixed);
    // cout.precision(3);
    map<string, int> dict;
    string s;
    int N, M, cnt = 0;
    cin >> N >> M;
    REP(i, 0, N) {
        cin >> s;
        dict.insert({s, 0});
    }
    REP(i, 0, M) {
        cin >> s;
        auto it = dict.find(s);
        if (it != dict.end())
            (*it).second += 1;
    }
    FOREACH(it, dict) { cnt += (*it).second; }
    cout << cnt;

    return 0;
}