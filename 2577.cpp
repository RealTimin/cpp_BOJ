// URL: https://www.acmicpc.net/problem/2577
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
    int A, B, C;
    int result = 1;
    int rem;
    int count[10] = {0};
    cin >> A >> B >> C;
    result = A * B * C;
    while (result != 0) {
        rem = result % 10;
        count[rem]++;
        result /= 10;
    }
    REP(i, 0, 10) { cout << count[i] << endl; }

    return 0;
}