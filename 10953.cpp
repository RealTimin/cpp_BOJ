// URL: https://www.acmicpc.net/problem/10953
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
    int N, x, y;
    string s;
    cin >> N;
    REP(i, 0, N) {
        cin >> s;
        x = (int)(s[0] - '0');
        y = (int)(s[2] - '0');
        cout << x + y << endl;
    }

    return 0;
}