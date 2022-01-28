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
    int N, M;
    cin >> N;
    vector<int> nums;
    int num;
    REP(i, 0, N)
    {
        cin >> num;
        nums.push_back(num);
    }
    sort(nums.begin(), nums.end());
    auto it = nums.begin();
    cin >> M;
    REP(i, 0, M)
    {
        cin >> num;
        it = lower_bound(nums.begin(), nums.end(), num);
        if ((*it) == num)
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
    }
    return 0;
}