// URL: https://www.acmicpc.net/problem/9498
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
    int score;
    cin >> score;
    if (90 <= score && score <= 100) {
        cout << 'A';
    } else if (80 <= score && score <= 89) {
        cout << 'B';
    } else if (70 <= score && score <= 79) {
        cout << 'C';
    } else if (60 <= score && score <= 69) {
        cout << 'D';
    } else {
        cout << 'F';
    }

    return 0;
}