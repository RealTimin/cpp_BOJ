// URL: https://www.acmicpc.net/problem/2457
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
    int s1, s2, e1, e2;
    vector<pair<pii, pii>> dates;
    pii sday, eday;
    int N;
    cin >> N;
    REP(i, 0, N) {
        cin >> s1 >> s2 >> e1 >> e2;
        sday = (pii(s1, s2) < pii(3, 1)) ? pii(3, 1) : pii(s1, s2);
        eday = (pii(e1, e2) > pii(12, 1)) ? pii(12, 1) : pii(e1, e2);
        if (eday <= pii(3, 1) || sday > pii(11, 30))
            continue;
        eday.first = -eday.first;
        eday.second = -eday.second;
        dates.push_back({sday, eday});
    }
    dates.push_back({{12, 2}, {-12, -3}});
    sort(dates.begin(), dates.end());
    pii total(3, 1);
    int idx, nidx = -1, result = 0;
    for (auto it = dates.begin(); it != dates.end(); it++) {
        sday = (*it).first;
        idx = it - dates.begin();
        if (sday > total) {
            if (nidx == -1) {
                break;
            } else {
                eday = dates[nidx].second;
                eday.first = -eday.first;
                eday.second = -eday.second;
                if (total == eday)
                    break;
                result++;
                total = eday;
                it--;
                continue;
            }
        }
        eday = (*it).second;
        if (nidx == -1) {
            nidx = idx;
        } else if (dates[nidx].second > eday) {
            nidx = idx;
        }
        if (total == pii(12, 1))
            break;
    }
    if (total == pii(12, 1))
        cout << result;
    else
        cout << 0;

    return 0;
}