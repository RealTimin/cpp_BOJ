// URL: https://www.acmicpc.net/problem/2908
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
    string a, b;
    cin >> a >> b;
    reverse(ALL(a));
    reverse(ALL(b));
    REP(i, 0, 3) {
        if (a[i] > b[i]) {
            cout << a << endl;
            break;
        } else if (a[i] < b[i]) {
            cout << b << endl;
            break;
        }
    }

    return 0;
}