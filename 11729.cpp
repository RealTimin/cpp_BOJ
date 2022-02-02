// URL: https://www.acmicpc.net/problem/00000
#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

// int oc[3];

void Hanoi(int step, int from, int to)
{
    // oc[0] = 0;
    // oc[1] = 0;
    // oc[2] = 0;
    // oc[from - 1] = 1;
    // oc[to - 1] = 1;
    int other = 6 - from - to;
    // REP(i, 0, 3)
    // if (oc[i] == 0)
    //     other = i + 1;
    if (step == 1)
    {
        cout << from << ' ' << to << endl;
        return;
    }
    Hanoi(step - 1, from, other);
    cout << from << ' ' << to << endl;
    Hanoi(step - 1, other, to);
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout.setf(ios::fixed);
    // cout.precision(3);
    int N;
    cin >> N;
    cout << ((1 << N) - 1) << endl;
    Hanoi(N, 1, 3);

    return 0;
}