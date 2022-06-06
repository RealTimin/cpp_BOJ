// URL: https://www.acmicpc.net/problem/3053
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
#define PI 3.141592653589793238

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.setf(ios::fixed);
    cout.precision(6);
    ll R;
    double area;
    cin >> R;
    area = PI * R * R;
    cout << area << endl;
    area = (double)2 * R * R;
    cout << area << endl;

    return 0;
}