// URL: https://www.acmicpc.net/problem/11501
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
    int T, N, maxPrice, tempi, ri;
    vi maxi;
    vector<ll> price;
    vector<ll> sums;
    ll ts;
    ll result, stock;
    int nk, k;

    cin >> T;
    REP(t, 0, T) {
        cin >> N;
        maxi.assign(N, 0);
        price.assign(N, 0);
        sums.assign(N, 0);
        ts = 0;
        REP(i, 0, N) { cin >> price[i]; }
        maxPrice = -1;
        REP(i, 0, N) {
            ri = N - 1 - i;
            if (price[ri] > maxPrice) {
                tempi = ri;
                maxPrice = price[tempi];
                ts = -price[tempi];
            }
            ts += price[ri];
            sums[ri] = ts;
            maxi[ri] = tempi;
        }
        result = 0;
        k = 0;
        while (k < N) {
            nk = maxi[k];
            stock = nk - k;
            result = result + stock * price[nk] - sums[k];
            k = nk + 1;
        }
        cout << result << endl;
    }

    return 0;
}