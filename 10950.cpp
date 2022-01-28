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
    int N;
    cin >> N;
    int A, B;
    REP(i, 0, N)
    {
        cin >> A >> B;
        cout << A + B << endl;
    }

    return 0;
}