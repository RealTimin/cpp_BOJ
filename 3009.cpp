// URL: https://www.acmicpc.net/problem/3009
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

    int a, b, c, d, e, f;
    int x, y;
    cin >> a >> b >> c >> d >> e >> f;
    x = (a == c ? e : (a == e ? c : a));
    y = (b == d ? f : (b == f ? d : b));
    cout << x << ' ' << y << endl;
    return 0;
}