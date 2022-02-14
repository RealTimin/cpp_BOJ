// #include <stdio.h>
// #include <string.h>

// char str1[1001]={0};
// char str2[1001]={0};
// int count[1000]={0};
// int len1, len2;

// int main(void)
// {
//     int i, j, k;
//     int max;
//     scanf("%s %s", &str1, &str2);
//     len1 = strlen(str1);
//     len2 = strlen(str2);
//     for(i=0;i<len1;i++)
//     {
//         for(j=len2-1;j>=0;j--)
//         {
//             if(str1[i]==str2[j])
//             {
//                 max=0;
//                 for(k=0;k<j;k++)
//                 {
//                     if(count[k]>max)
//                     {
//                         max = count[k];
//                     }
//                 }
//                 count[j] = max + 1;

//                 // count[j]++;
//                 // for(k=j+1;k<len2;k++)
//                 // {
//                 //     if(count[k]<count[j])
//                 //     {
//                 //         count[k] = count[j];
//                 //     }
//                 // }
//                 // This doesn't work.
//             }
//         }
//     }
//     max=0;
//     for(i=0;i<len2;i++)
//     {
//         if(count[i]>max)
//         {
//             max = count[i];
//         }
//     }
//     printf("%d", max);
//     // printf("%d", count[len2-1]);
//     return 0;
// }

// URL: https://www.acmicpc.net/problem/9251
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define endl '\n'

int maxWith[1001];
int maxLen[1001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout.setf(ios::fixed);
    // cout.precision(3);
    string s1, s2;
    cin >> s1;
    cin >> s2;
    int n1 = s1.size(), n2 = s2.size();
    int m;
    int result = 0;
    REP(j, 0, n2)
    {
        m = 0;
        REP(i, 0, n1)
        {
            if (s1[i] == s2[j])
            {
                maxWith[i] = maxLen[i] + 1;
            }
            maxLen[i] = m;
            m = max(m, maxWith[i]);
        }
        result = max(result, m);
    }

    cout << result;

    return 0;
}