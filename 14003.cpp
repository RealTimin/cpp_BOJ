// reference: https://seungkwan.tistory.com/8 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> v;       // minimum end number of length (i) LIS
    vector<int> v_ind;   // index
    vector<int> arr;     // all number
    vector<int> prevInd; // space complexity: O(n)
    vector<int> answer;  // array to save answer (instead of stack)
    int num;
    int size;
    int answerIndex;
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        arr.push_back(num);
        if (v.empty()) // i==0
        {
            v.push_back(num);
            v_ind.push_back(i);
            prevInd.push_back(i);
        }
        else if (num > v.back())
        {
            v.push_back(num);
            v_ind.push_back(i);
            prevInd.push_back(v_ind[v.size() - 2]);
        }
        else
        {
            auto it = lower_bound(v.begin(), v.end(), num);
            int insertIndex = it - v.begin();
            *(it) = num;
            v_ind[insertIndex] = i;
            if (insertIndex == 0)
                prevInd.push_back(i);
            else
                prevInd.push_back(v_ind[insertIndex - 1]);
        }
    }

    size = v.size();
    answer.assign(size, 0);
    answerIndex = v_ind.back();
    for (int i = size - 1; i >= 0; i--)
    {
        answer[i] = arr[answerIndex];
        answerIndex = prevInd[answerIndex];
    }
    cout << size << '\n';
    for (auto it = answer.begin(); it != answer.end(); it++)
    {
        cout << (*it) << ' ';
    }
    return 0;
}

// #include <iostream>
// #include <vector>

// using namespace std;

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);

//     int N;
//     cin >> N;
//     vector<int> v;
//     vector<vector<int>> mem; // space complexity: O(n^2)
//     int num;
//     int size;
//     for (int i = 0; i < N; i++)
//     {
//         cin >> num;
//         if (v.empty())
//         {
//             mem.push_back(vector<int>(1, num));
//             v.push_back(num);
//         }
//         else if (num > v.back())
//         {
//             size = v.size();
//             mem.push_back(mem[size - 1]);
//             mem[size].push_back(num);
//             v.push_back(num);
//         }
//         else
//         {
//             auto it = lower_bound(v.begin(), v.end(), num);
//             int index = it - v.begin();
//             *(it) = num;
//             if (index == 0)
//                 mem[index] = vector<int>(1, num);
//             else
//             {
//                 mem[index] = mem[index - 1];
//                 mem[index].push_back(num);
//             }
//         }
//     }
//     size = v.size();
//     cout << size << endl;
//     auto end = mem[size - 1].end();
//     for (auto it = mem[size - 1].begin(); it != end; it++)
//     {
//         cout << (*it) << ' ';
//     }
//     return 0;
// }