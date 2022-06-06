// URL: https://www.acmicpc.net/problem/1157
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
    string s;
    vi cnt(26, 0);
    int maxCnt, maxi;
    bool dupl;
    cin >> s;
    FOREACH(it, s) {
        if ((*it) <= 'Z') {
            (*it) += ('a' - 'A');
        }
    }
    FOREACH(it, s) { cnt[(int)((*it) - 'a')]++; }
    maxCnt = -1, maxi = -1, dupl = false;
    REP(i, 0, 26) {
        if (maxCnt == cnt[i]) {
            dupl = true;
        } else if (maxCnt < cnt[i]) {
            dupl = false;
            maxCnt = cnt[i], maxi = i;
        }
    }

    cout << (dupl ? '?' : (char)(maxi + 'A')) << endl;

    return 0;
}