// URL: https://www.acmicpc.net/problem/4153
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
    int a, b, c;
    int A, B, C;
    bool chk = true;
    while (chk) {
        cin >> a >> b >> c;
        if (a == 0 && b == 0 && c == 0)
            break;
        C = max(a, max(b, c));
        A = min(a, min(b, c));
        B = a + b + c - A - C;
        if ((ll)C * C == (ll)A * A + (ll)B * B)
            cout << "right" << endl;
        else
            cout << "wrong" << endl;
    }

    return 0;
}