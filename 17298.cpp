#include <iostream>
#include <string>
#include <deque>
#include <vector>
using namespace std;

struct elem
{
    elem(int _i, int _v) : i(_i), v(_v) {}
    int i;
    int v;
};

int main()
{
    int N, num;
    deque<elem> d;

    cin >> N;
    vector<int> NGE(N, -1);
    // cout << NGE.back() << endl;

    for (int i = 0; i < N; i++)
    {
        cin >> num;

        while (!d.empty())
        {
            if (d.back().v < num)
            {
                NGE[d.back().i] = num;
                d.pop_back();
            }
            else
                break;
        }
        d.push_back(elem(i, num));
    }

    // print
    for (int i = 0; i < N; i++)
    {
        cout << NGE[i] << ' ';
    }
    return 0;
}