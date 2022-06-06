// URL: https://www.acmicpc.net/problem/2775
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
    int T, K, N;
    vi nums;
    int sum;
    cin >> T;
    REP(t, 0, T) {
        cin >> K >> N;
        nums.assign(N, 1);
        REP(k, -1, K) {
            sum = 0;
            FOREACH(it, nums) { sum += (*it); }
            for (int n = N - 1; n >= 0; n--) {
                sum -= nums[n];
                nums[n] += sum;
            }
        }
        cout << nums[N - 1] << endl;
    }

    return 0;
}