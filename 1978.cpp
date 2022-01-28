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
    int num;
    int pCount = 0;
    bool isPrime;
    REP(i, 0, N)
    {
        cin >> num;
        isPrime = true;
        for (int d = 2; d * d <= num; d++)
        {
            if (num % d == 0)
            {
                isPrime = false;
                break;
            }
        }

        if (num == 1)
            isPrime = false;

        if (isPrime)
            pCount++;
    }
    cout << pCount;

    return 0;
}