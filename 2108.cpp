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
    // cout.precision(0);
    int N;
    vi nums;
    cin >> N;
    nums.assign(N, 0);
    REP(i, 0, N) { cin >> nums[i]; }
    sort(ALL(nums));
    // average
    double total = 0;
    REP(i, 0, N) { total += nums[i]; }
    double avg = round(total / N);
    int temp = avg;
    cout << temp << endl;
    // middle
    cout << nums[N / 2] << endl;
    // freq
    int freqNum = -10000, curNum = -10000;
    int freqCnt = 0, curCnt = 0;
    bool dupl = false;
    REP(i, 0, N) {
        if (nums[i] != curNum) {
            curNum = nums[i];
            curCnt = 1;
        } else {
            curCnt++;
        }

        if (freqCnt < curCnt) {
            dupl = false;
            freqNum = curNum;
            freqCnt = curCnt;
        } else if (freqCnt == curCnt && !dupl) {
            dupl = true;
            freqNum = curNum;
            freqCnt = curCnt;
        }
    }
    cout << freqNum << endl;
    // range
    cout << nums[N - 1] - nums[0] << endl;

    return 0;
}