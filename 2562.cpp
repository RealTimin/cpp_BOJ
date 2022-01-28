#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int max = 0;
    int max_i = -1;
    int num;
    for (int i = 1; i <= 9; i++)
    {
        cin >> num;
        if (num > max)
        {
            max = num;
            max_i = i;
        }
    }
    cout << max << endl
         << max_i << endl;
    return 0;
}