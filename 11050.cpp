#include <iostream>
#include <algorithm>
#include <vector>

#define REP(i, a, b) for (int i = (a); i < (b); i++)

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, K;

    int result;
    cin >> N >> K;

    result = 1;
    REP(i, 0, K)
    {
        result *= (N - i);
    }
    REP(i, 0, K)
    {
        result /= (i + 1);
    }
    cout << result;
    return 0;
}