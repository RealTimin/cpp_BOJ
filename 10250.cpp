// URL: https://www.acmicpc.net/problem/10250
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
    int T, N, H, W, f, d;
    cin >> T;
    REP(t, 0, T) {
        cin >> H >> W >> N;
        f = N % H;
        d = N / H;
        d += (f == 0 ? 0 : 1);
        f = (f == 0 ? H : f);
        cout << f;
        d < 10 ? (cout << 0 << d << endl) : (cout << d << endl);
    }

    return 0;
}