// URL: https://www.acmicpc.net/problem/11659
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
    int N, M;
    int i, j;
    vi sums, nums;
    cin >> N >> M;
    nums.assign(N, 0);
    sums.assign(N, 0);
    REP(i, 0, N) {
        cin >> nums[i];
        sums[i] = (i == 0 ? nums[i] : nums[i] + sums[i - 1]);
    }
    REP(m, 0, M) {
        cin >> i >> j;
        i--, j--;
        cout << (i == 0 ? sums[j] : sums[j] - sums[i - 1]) << endl;
    }

    return 0;
}