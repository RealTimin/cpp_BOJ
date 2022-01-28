#include <iostream>
#include <algorithm>
#include <vector>

#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define N 8

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    bool ascending = true;
    bool descending = true;
    int num;
    REP(i, 0, N)
    {
        cin >> num;
        if (num != i + 1)
            ascending = false;
        if (num != N - i)
            descending = false;
    }

    if (ascending)
        cout << "ascending";
    else if (descending)
        cout << "descending";
    else
        cout << "mixed";

    return 0;
}