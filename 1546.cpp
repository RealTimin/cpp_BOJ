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
    int N, total = 0, temp, maxScore = 0;
    cin >> N;
    REP(i, 0, N) {
        cin >> temp;
        maxScore = max(maxScore, temp);
        total += temp;
    }
    double average = (double)total / N * 100 / maxScore;
    cout << average;
    return 0;
}