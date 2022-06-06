// URL: https://www.acmicpc.net/problem/2480
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
    int a, b, c, res = 0;
    cin >> a >> b >> c;
    if (a == b && b == c) {
        res = 10000 + 1000 * a;

    } else if (a == b || b == c || c == a) {

        res = b == c ? 1000 + 100 * b : 1000 + 100 * a;
    } else {
        res = 100 * max(a, max(b, c));
    }
    cout << res;

    return 0;
}