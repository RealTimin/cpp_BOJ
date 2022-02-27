// URL: https://www.acmicpc.net/problem/10871
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
    int N, X;
    cin >> N >> X;
    int num;
    REP(i, 0, N) {
        cin >> num;
        if (num < X)
            cout << num << ' ';
    }

    return 0;
}