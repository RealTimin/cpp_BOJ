#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

#define REP(i, a, b) for (int i = (a); i < (b); i++)

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    map<int, int> dict;
    vector<int> nums;
    int num;
    int N;
    cin >> N;
    nums.assign(N, 0);
    REP(i, 0, N)
    {
        cin >> num;
        nums[i] = num;
        dict.insert(make_pair(num, 0));
    }
    int index = 0;
    for (auto it = dict.begin(); it != dict.end(); it++)
    {
        (*it).second = index;
        index++;
    }
    auto it_found = dict.begin();
    REP(i, 0, N)
    {
        num = nums[i];
        it_found = dict.find(num);
        cout << (*it_found).second << ' ';
    }

    return 0;
}