// URL: https://www.acmicpc.net/problem/7869
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define endl '\n'

const double PI = 3.1415926535;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.setf(ios::fixed);
    cout.precision(3);
    double x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    double d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    if (d >= r1 + r2)
        cout << (double)(0);
    else if (r1 >= d + r2)
        cout << r2 * r2 * PI;
    else if (r2 >= d + r1)
        cout << r1 * r1 * PI;
    else {
        double c1 = (r1 * r1 + d * d - r2 * r2) / (2 * r1 * d);
        double c2 = (r2 * r2 + d * d - r1 * r1) / (2 * r2 * d);
        double t1 = 2 * acos(c1);
        double t2 = 2 * acos(c2);
        double ss = (r1 * r1 * t1 + r2 * r2 * t2) / 2;
        // double sq = (r1 * d * sin(acos(c1)));
        double sq = r1 * r1 * sin(t1) / 2 + r2 * r2 * sin(t2) / 2;
        double result = ss - sq;
        // result = floor(result * 1000) / 1000;
        cout << result;
    }

    return 0;
}