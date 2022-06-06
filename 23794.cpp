// URL: https://www.acmicpc.net/problem/23794
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
    REP(j, 0, N + 2) cout << '@';
    cout << endl;
    REP(i, 0, N) {
        cout << '@';
        REP(j, 0, N) cout << ' ';
        cout << '@' << endl;
    }
    REP(j, 0, N + 2) cout << '@';
    cout << endl;

    return 0;
}