// URL: https://www.acmicpc.net/problem/12852
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define endl '\n'
#define MAXN 1000001

int minCount[MAXN] = {0};
int prevInt[MAXN] = {0};
int N;

void FindMin(int index, int prevIndex)
{
    if (index > N)
        return;
    int prevCount = minCount[prevIndex];
    if (minCount[index] > prevCount + 1)
    {
        minCount[index] = prevCount + 1;
        prevInt[index] = prevIndex;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout.setf(ios::fixed);
    // cout.precision(3);
    minCount[1] = 0;
    prevInt[1] = 1;
    cin >> N;
    REP(i, 2, N + 1)
    {
        minCount[i] = INT_MAX;
    }
    REP(i, 1, N + 1)
    {
        FindMin(i * 2, i);
        FindMin(i * 3, i);
        FindMin(i + 1, i);
    }
    cout << minCount[N] << endl;
    int pi = N;
    while (pi != 1)
    {
        cout << pi << ' ';
        pi = prevInt[pi];
    }
    cout << 1;

    return 0;
}