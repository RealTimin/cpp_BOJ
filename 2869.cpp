// URL: https://www.acmicpc.net/problem/00000
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
    int A, B, V;
    int result = 1;
    cin >> A >> B >> V;
    V -= A;
    if (V > 0) {
        double temp = (double)V / (A - B);
        result += ceil(temp);
    }

    cout << result;

    return 0;
}