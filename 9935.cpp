// URL: https://www.acmicpc.net/problem/9935
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout.setf(ios::fixed);
    // cout.precision(3);
    string s, p;
    string result;
    stack<int> st;
    cin >> s >> p;
    int ns = s.size();
    int np = p.size();
    int i = 0, j = 0;
    for (i = 0; i < ns; i++) {
        result.push_back(s[i]);
        if (s[i] == p[j]) {
            if (j == np - 1) {
                REP(k, 0, np) { result.pop_back(); }
                if (st.empty())
                    j = 0;
                else {
                    j = st.top();
                    st.pop();
                }
            } else {
                j++;
            }
        } else {
            if (j > 0) {
                // compare i with j=0 again
                if (s[i] == p[0]) {
                    st.push(j);
                    j = 1;
                } else {
                    while (!st.empty())
                        st.pop();
                    j = 0;
                }
            } else {
                while (!st.empty())
                    st.pop();
            }
        }
    }

    if (result.empty())
        cout << "FRULA";
    else
        cout << result;

    return 0;
}

// // KMP algorithm

// vi pi;
// vi res;

// void getPi(string &p) {
//     int np = p.size();
//     int i = 0, j = 0;
//     pi.assign(np, 0);
//     for (i = 1; i < np; i++) {
//         while (j > 0 && p[i] != p[j]) {
//             j = pi[j - 1];
//         }
//         if (p[i] == p[j]) {
//             j++;
//         }
//         pi[i] = j;
//     }
// }

// void getKMP(string &s, string &p) {
//     int ns = s.size(), np = p.size();
//     int i = 0, j = 0;
//     for (i = 0; i < ns; i++) {
//         while (j > 0 && s[i] != p[j])
//             j = pi[j - 1];
//         if (s[i] == p[j]) {
//             if (j == np - 1) {
//                 res.push_back(i - np + 1);
//                 j = pi[j];
//             } else {
//                 j++;
//             }
//         }
//     }
// }

// int main() {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     // cout.setf(ios::fixed);
//     // cout.precision(3);
//     string s, p, temp;
//     cin >> s >> p;
//     int np = p.size();
//     bool finished = false;
//     auto si = s.begin(), ei = s.end();
//     getPi(p);
//     while (!finished) {
//         res.clear();
//         getKMP(s, p);
//         if (res.empty())
//             finished = true;
//         else {
//             for (auto it = res.rbegin(); it != res.rend(); it++) {
//                 si = s.begin() + (*it);
//                 ei = si + np;
//                 s.erase(si, ei);
//             }
//         }
//     }

//     if (s.empty())
//         cout << "FRULA";
//     else
//         cout << s;

//     return 0;
// }