// URL: https://www.acmicpc.net/problem/2446
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
    int N;
    cin >> N;
    REP(i, 0, N) {
        REP(j, 0, i) { cout << ' '; }
        REP(j, 2 * i, 2 * N - 1) { cout << '*'; }
        cout << endl;
    }
    for (int i = N - 2; i >= 0; i--) {
        REP(j, 0, i) { cout << ' '; }
        REP(j, 2 * i, 2 * N - 1) { cout << '*'; }
        cout << endl;
    }

    return 0;
}