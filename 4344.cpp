// URL: https://www.acmicpc.net/problem/4344
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
    cout.setf(ios::fixed);
    cout.precision(3);
    int C;
    cin >> C;
    int N, temp, cnt;
    double average, result;
    vi nums;
    REP(c, 0, C) {
        cin >> N;
        nums.assign(N, 0);
        average = 0;
        cnt = 0;
        REP(i, 0, N) {
            cin >> nums[i];
            average += nums[i];
        }
        average /= N;
        REP(i, 0, N) {
            if (nums[i] > average)
                cnt++;
        }
        result = (double)cnt / N * 100;
        cout << result << '%' << endl;
    }

    return 0;
}