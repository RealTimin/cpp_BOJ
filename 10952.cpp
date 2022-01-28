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
    int A, B;
    while (1)
    {
        cin >> A >> B;
        if (A == 0 && B == 0)
            break;
        cout << A + B << endl;
    }

    return 0;
}