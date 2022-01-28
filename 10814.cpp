#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define REP(i, a, b) for (int i = (a); i < (b); i++)

using namespace std;

struct Info
{
    int age;
    string name;
};

bool comp(Info i1, Info i2)
{
    return i1.age < i2.age;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    int age;
    string name;
    vector<Info> dict;
    REP(i, 0, N)
    {
        cin >> age >> name;
        Info info = {age, name};
        dict.push_back(info);
    }
    stable_sort(dict.begin(), dict.end(), comp);

    REP(i, 0, N)
    {
        cout << dict[i].age << ' ' << dict[i].name << '\n';
    }

    return 0;
}