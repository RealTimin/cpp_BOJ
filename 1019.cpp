// URL: https://www.acmicpc.net/problem/1019
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define endl '\n'

ll power(ll base, ll exp) {
    ll result = 1;
    REP(i, 0, exp) { result *= base; }
    return result;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout.setf(ios::fixed);
    // cout.precision(3);
    ll N;
    cin >> N;
    ll tempL, temp = N, len = 0;
    ll count[10] = {0};
    int digits[10] = {0};
    while (temp != 0) {
        digits[len] = temp % 10;
        temp /= 10;
        len++;
    }

    // count (len-1) ~ 1 digits numbers
    if (len != 1) {
        REP(k, 1, 10) { count[k] += 1; }
    }
    REP(i, 2, len) {
        count[0] += 9 * power(10, i - 2) * (i - 1);
        REP(k, 1, 10) {
            count[k] += power(10, i - 1);
            count[k] += 9 * power(10, i - 2) * (i - 1);
        }
    }

    // count len digits numbers
    if (len == 1) {
        REP(i, 1, N + 1) { count[i] += 1; }
    } else {
        for (int l = len - 1; l >= 0; l--) {
            // find temp and add
            if (l == len - 1) {
                temp = 1;
            } else if (l == len - 2) {
                temp = digits[len - 1];
            } else {
                temp = 0;
                for (int i = len - 1; i > l; i--) {
                    temp *= 10;
                    temp += digits[i];
                }
                temp = temp - power(10, (len - l - 2)) + 1;
            }
            temp *= power(10, l);

            // find tempL
            tempL = 0;
            for (int i = l - 1; i >= 0; i--) {
                tempL *= 10;
                tempL += digits[i];
            }
            tempL++;

            // add temp & tempL to count[]
            if (l == len - 1) {
                REP(i, 1, 10) {
                    if (i < digits[len - 1]) {
                        count[i] += temp;
                    } else {
                        count[i] += tempL;
                        break;
                    }
                }
            } else if (l == 0) {
                REP(i, 0, 10) {
                    count[i] += temp;
                    if (i == digits[l]) {
                        temp--;
                    }
                }
            } else {
                REP(i, 0, 10) {
                    if (i < digits[l]) {
                    } else if (i == digits[l]) {
                        temp /= power(10, l);
                        temp--;
                        temp *= power(10, l);
                        count[i] += tempL;
                    } else {
                    }
                    count[i] += temp;
                }
            }
        }
    }

    REP(i, 0, 10) { cout << count[i] << ' '; }

    return 0;
}