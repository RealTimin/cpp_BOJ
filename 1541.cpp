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
    string s;
    cin >> s;
    s.push_back('-');
    bool minusOn = false;
    int opi = -1, ci, num;
    vi nums;
    vi ops;
    for (auto it = s.begin(); it != s.end(); it++) {
        if ((*it) == '-' || (*it) == '+') {
            num = 0;
            opi++;
            ci = it - s.begin();
            while (opi < ci) {
                num *= 10;
                num += (int)(s[opi] - '0');
                opi++;
            }
            nums.push_back(num);
            if ((*it) == '-') {
                minusOn = true;
                ops.push_back(0);
            } else if ((*it) == '+') {
                if (minusOn)
                    ops.push_back(0);
                else
                    ops.push_back(1);
            }
        }
    }
    int result = nums[0];
    int opCount = ops.size() - 1;
    REP(i, 0, opCount) {
        if (ops[i])
            result += nums[i + 1];
        else
            result -= nums[i + 1];
    }
    cout << result;

    return 0;
}