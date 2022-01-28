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
    int max = -99999999;
    int min = 99999999;
    int num;
    int N;
    cin >> N;
    REP(i, 0, N)
    {
        cin >> num;
        if (max < num)
            max = num;
        if (min > num)
            min = num;
    }
    cout << min << ' ' << max;

    return 0;
}