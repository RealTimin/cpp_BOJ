// URL: https://www.acmicpc.net/problem/2559
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
#define INF INT_MAX
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout.setf(ios::fixed);
    // cout.precision(3);
    int N, K;
    cin >> N >> K;
    vi nums(N, 0);
    REP(i, 0, N) cin >> nums[i];
    int k = 1, maxSum = -INF, tempSum = 0, j = 0;
    REP(i, 0, N) {
        if (k < K) {
            tempSum += nums[i];
            k++;
        } else {
            tempSum += nums[i];
            maxSum = max(maxSum, tempSum);
            tempSum -= nums[j];
            j++;
        }
    }
    cout << maxSum;

    return 0;
}