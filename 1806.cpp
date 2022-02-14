// URL: https://www.acmicpc.net/problem/1806
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define endl '\n'

// two pointer technique

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout.setf(ios::fixed);
    // cout.precision(3);
    int N, S;
    vi nums;
    int total = 0;
    int i = 0, j = 0;
    int minLen = INT_MAX;
    cin >> N >> S;
    nums.assign(N, 0);
    REP(n, 0, N)
    {
        cin >> nums[n];
    }
    total = nums[i];
    while (j < N)
    {
        if (total < S)
        {
            j++;
            if (j < N)
                total += nums[j];
        }
        else
        {
            minLen = min(minLen, j - i + 1);
            total -= nums[i];
            i++;
        }
    }

    if (minLen == INT_MAX)
        cout << 0;
    else
        cout << minLen;

    return 0;
}