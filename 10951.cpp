// https://lollolzkk.tistory.com/15 when input range is not given - use !cin.eof()
// while (!cin.eof())
// {
// }

// https://bk-coding.tistory.com/9 baekJoon 10951
// while (cin >> a >> b)
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
    vector<int> v;
    while (cin >> A >> B)
    {
        cout << A + B << endl;
        // v.push_back(A + B);
    }
    // cout << v[v.size() - 1];
    return 0;
}