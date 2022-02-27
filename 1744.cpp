// URL: https://www.acmicpc.net/problem/1744
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
    int N;
    cin >> N;
    priority_queue<int> posNum;
    int zeroCount = 0, num, result = 0, n1, n2;
    priority_queue<int, vector<int>, greater<int>> negNum;
    REP(i, 0, N) {
        cin >> num;
        if (num < 0)
            negNum.push(num);
        else if (num == 0)
            zeroCount++;
        else
            posNum.push(num);
    }

    while (!posNum.empty()) {
        n1 = posNum.top();
        posNum.pop();
        if (posNum.empty()) {
            result += n1;
            continue;
        }
        n2 = posNum.top();
        posNum.pop();
        if (n1 == 1 || n2 == 1)
            result += (n1 + n2);
        else
            result += n1 * n2;
    }

    while (!negNum.empty()) {
        n1 = negNum.top();
        negNum.pop();
        if (negNum.empty()) {
            if (zeroCount == 0) {
                result += n1;
            }
            continue;
        }
        n2 = negNum.top();
        negNum.pop();
        result += n1 * n2;
    }

    cout << result << endl;
    return 0;
}