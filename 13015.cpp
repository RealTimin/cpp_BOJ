// URL: https://www.acmicpc.net/problem/13015
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
    REP(j, 0, N) cout << '*';
    REP(j, 0, 2 * N - 3) cout << ' ';
    REP(j, 0, N) cout << '*';
    cout << endl;
    REP(i, 1, N - 1) {
        REP(j, 0, i) cout << ' ';
        cout << '*';
        REP(j, 2, N) cout << ' ';
        cout << '*';
        REP(j, 0, 2 * N - 3 - 2 * i) cout << ' ';
        cout << '*';
        REP(j, 2, N) cout << ' ';
        cout << '*';
        cout << endl;
    }
    REP(j, 0, N - 1) cout << ' ';
    cout << '*';
    REP(j, 2, N) cout << ' ';
    cout << '*';
    REP(j, 2, N) cout << ' ';
    cout << '*';
    cout << endl;
    for (int i = N - 2; i >= 1; i--) {
        REP(j, 0, i) cout << ' ';
        cout << '*';
        REP(j, 2, N) cout << ' ';
        cout << '*';
        REP(j, 0, 2 * N - 3 - 2 * i) cout << ' ';
        cout << '*';
        REP(j, 2, N) cout << ' ';
        cout << '*';
        cout << endl;
    }
    REP(j, 0, N) cout << '*';
    REP(j, 0, 2 * N - 3) cout << ' ';
    REP(j, 0, N) cout << '*';
    cout << endl;
    return 0;
}