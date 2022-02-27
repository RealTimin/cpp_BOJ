// URL: https://www.acmicpc.net/problem/11021
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout.setf(ios::fixed);
    // cout.precision(3);
    int T, A, B;
    cin >> T;
    REP(i, 0, T) {
        cin >> A >> B;
        cout << "Case #" << i + 1 << ": " << A + B << endl;
    }

    return 0;
}