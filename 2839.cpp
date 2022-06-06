// URL: https://www.acmicpc.net/problem/2839
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
    int R = N % 5;
    int D = N / 5;
    int res = 0;
    switch (R) {
    case 0:
        res = D;
        break;
    case 1:
        res = D >= 1 ? (D - 1 + 2) : -1;
        break;
    case 2:
        res = D >= 2 ? (D - 2 + 4) : -1;
        break;
    case 3:
        res = (D + 1);
        break;
    case 4:
        res = D >= 1 ? (D - 1 + 3) : -1;
    default:
        break;
    }
    cout << res << endl;

    return 0;
}