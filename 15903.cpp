// URL: https://www.acmicpc.net/problem/15903
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
    // x and y don't need to be adjacent
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    ll num;
    int N, M;
    cin >> N >> M;
    REP(i, 0, N) {
        cin >> num;
        pq.push(num);
    }
    ll n1, n2, n3;
    REP(j, 0, M) {
        n1 = pq.top();
        pq.pop();
        n2 = pq.top();
        pq.pop();
        n3 = n1 + n2;
        pq.push(n3);
        pq.push(n3);
    }
    ll result = 0;
    while (!pq.empty()) {
        result += pq.top();
        pq.pop();
    }
    cout << result;

    return 0;
}

// int main() {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     // cout.setf(ios::fixed);
//     // cout.precision(3);
//     int N, M;
//     cin >> N >> M;
//     int mini;
//     ll minSum, n1, n2;
//     vector<ll> nums(N, 0);
//     vector<ll> sums(N, 0);
//     ll result = 0;
//     REP(i, 0, N) {
//         cin >> nums[i];
//         if (i > 0)
//             sums[i - 1] = nums[i] + nums[i - 1];
//     }
//     REP(j, 0, M) {
//         mini = -1;
//         minSum = LLONG_MAX;
//         REP(i, 0, N - 1) {
//             if (minSum > sums[i]) {
//                 minSum = sums[i];
//                 mini = i;
//             }
//         }
//         // adding cards
//         n1 = nums[mini];
//         n2 = nums[mini + 1];
//         if (mini > 0)
//             sums[mini - 1] += n2;
//         if (mini < N - 1)
//             sums[mini + 1] += n1;
//         sums[mini] += (n1 + n2);
//         nums[mini] += n2;
//         nums[mini + 1] += n1;
//     }

//     REP(i, 0, N) { result += nums[i]; }
//     cout << result;

//     return 0;
// }