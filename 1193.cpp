// URL: https://www.acmicpc.net/problem/1193
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
    int X, N, dif, a, b;
    cin >> X;
    N = 0;
    while (N * (N + 1) / 2 < X)
        N++;
    N--;
    dif = X - N * (N + 1) / 2;
    a = 0, b = N + 2;
    REP(i, 0, dif) {
        a++;
        b--;
    }
    if (N & 1) { // odd
        cout << a << '/' << b << endl;
    } else {
        cout << b << '/' << a << endl;
    }

    return 0;
}