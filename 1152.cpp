// URL: https://www.acmicpc.net/problem/1152
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
    int cnt = 1;
    getline(cin, s);
    FOREACH(it, s) {
        if (*it == ' ')
            cnt++;
    }
    if (*s.begin() == ' ')
        cnt--;
    if (*s.rbegin() == ' ')
        cnt--;
    cout << cnt << endl;

    return 0;
}