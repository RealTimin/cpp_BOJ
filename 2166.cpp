// URL: https://www.acmicpc.net/problem/2166
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define endl '\n'

// simple formula

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.setf(ios::fixed);
    cout.precision(1);
    ll area = 0;
    ll x, y, px, py;
    ll x0, y0;
    int N;
    cin >> N;
    cin >> px >> py;
    x0 = px;
    y0 = py;
    REP(i, 1, N)
    {
        cin >> x >> y;
        area += (px * y) - (py * x);
        px = x;
        py = y;
    }
    area += (px * y0) - (py * x0);
    double result = 0.5 * abs(area);
    cout << result;

    return 0;
}