// URL: https://www.acmicpc.net/problem/2581
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
    int x, y;
    int minNum = -1, total = 0;
    cin >> x >> y;
    REP(n, x, y + 1) {
        if (n == 1)
            continue;
        int i = 2;
        bool prime = true;
        while (prime && i * i <= n) {
            if (n % i == 0)
                prime = false;
            i++;
        }
        if (prime) {
            if (minNum == -1)
                minNum = n;
            total += n;
        }
    }
    if (minNum != -1)
        cout << total << endl;
    cout << minNum << endl;
    return 0;
}