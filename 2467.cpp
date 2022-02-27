// URL: https://www.acmicpc.net/problem/00000
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout.setf(ios::fixed);
    // cout.precision(3);
    vi negNums, posNums;
    reverse(negNums.begin(), negNums.end());

    int N, num, minVal, val, p, n;
    bool negExist = false, posExist = false;
    pii result = {0, 0};
    cin >> N;
    REP(i, 0, N) {
        cin >> num;
        if (num < 0)
            negNums.push_back(-num);
        else
            posNums.push_back(num);
    }
    reverse(negNums.begin(), negNums.end());

    if (negNums.empty()) {
        cout << posNums[0] << ' ' << posNums[1];
    } else if (posNums.empty()) {
        cout << -negNums[1] << ' ' << -negNums[0];
    } else {
        minVal = INT_MAX;
        if (posNums.size() >= 2) {
            val = posNums[0] + posNums[1];
            if (minVal > val) {
                result = {posNums[0], posNums[1]};
                minVal = val;
            }
        }
        if (negNums.size() >= 2) {
            val = negNums[0] + negNums[1];
            if (minVal > val) {
                result = {-negNums[1], -negNums[0]};
                minVal = val;
            }
        }

        for (auto pit = posNums.begin(); pit != posNums.end(); pit++) {
            auto nit = lower_bound(negNums.begin(), negNums.end(), (*pit));
            p = (*pit);
            if (nit != negNums.end()) {
                n = (*nit);
                val = abs(p - n);
                if (minVal > val) {
                    result = {-n, p};
                    minVal = val;
                }
            }
            if (nit != negNums.begin()) {
                nit--;
                n = (*nit);
                val = abs(p - n);
                if (minVal > val) {
                    result = {-n, p};
                    minVal = val;
                }
            }
        }
        cout << result.first << ' ' << result.second;
    }

    return 0;
}