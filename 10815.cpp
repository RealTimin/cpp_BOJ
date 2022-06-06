// URL: https://www.acmicpc.net/problem/10815
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
    int N, M, k;
    bool ex;
    cin >> N;
    vi nums(N, 0);
    REP(i, 0, N) { cin >> nums[i]; }
    sort(ALL(nums));
    cin >> M;
    REP(i, 0, M) {
        cin >> k;
        auto it = lower_bound(ALL(nums), k);
        if (it == nums.end())
            ex = false;
        else if (*it != k)
            ex = false;
        else
            ex = true;
        cout << ex << ' ';
    }

    return 0;
}