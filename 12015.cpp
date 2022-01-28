// #include <iostream>
// #include <map>

// using namespace std;

// int main()
// {
//     int N;
//     cin >> N;
//     int num;
//     int max_len = 1;
//     int prev_len;
//     int len;
//     map<int, int> m;

//     for (int i = 0; i < N; i++)
//     {
//         cin >> num;
//         auto [it, insertSuccess] = m.insert(make_pair(num, 1));
//         if (it != m.begin())
//         {
//             it--;
//             len = (*it).second + 1;
//             it++;
//             if (len > (*it).second)
//                 (*it).second = len;
//             if (len > max_len)
//             {
//                 max_len = len;
//             }
//             for (; it != m.end(); it++)
//             {
//                 if (len > (*it).second)
//                     (*it).second = len;
//             }
//         }
//     }

//     cout << max_len;
//     return 0;
// }


// reference: https://seungkwan.tistory.com/8 

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> v;
    int num;
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        if (v.empty() || num > v.back())
            v.push_back(num);
        else
            *(lower_bound(v.begin(), v.end(), num)) = num;
    }
    cout << v.size();
    return 0;
}