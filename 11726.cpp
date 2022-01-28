#include <iostream>
#include <algorithm>
#include <vector>

#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define MOD 10007
using namespace std;

// fibonacci sequence f(n) = f(n-2) + f(n-1)
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int> f;
    int N;
    cin >> N;
    f.push_back(1);
    f.push_back(2);
    REP(i, 2, N)
    {
        f.push_back((f[i - 2] + f[i - 1]) % MOD);
    }
    cout << f[N - 1];

    return 0;
}