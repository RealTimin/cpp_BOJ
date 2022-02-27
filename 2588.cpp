// URL: https://www.acmicpc.net/problem/2588
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
    int n1, n2;
    cin >> n1 >> n2;
    int temp = n2, x;
    REP(i, 0, 3) {
        x = temp % 10;
        cout << n1 * x << endl;
        temp /= 10;
    }
    cout << n1 * n2;
    return 0;
}