// URL: https://www.acmicpc.net/problem/17478
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define endl '\n'
#define ALL(v) (v).begin(), (v).end()
#define FOREACH(it, v) for (__typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

void PrintBar(int cnt) { REP(i, 0, cnt) cout << "____"; }

void PrintScript(int cnt, int step) {
    PrintBar(cnt);
    cout << "What is JaeQui?" << endl;
    if (step == 0) {
        PrintBar(cnt);
        cout << "self-called func" << endl;
    } else {
        PrintBar(cnt);
        cout << "Listen. " << endl;
        PrintBar(cnt);
        cout << "There was a man. " << endl;
        PrintBar(cnt);
        cout << "Another man asked the man..." << endl;
        PrintScript(cnt + 1, step - 1);
    }
    PrintBar(cnt);
    cout << "said the man." << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout.setf(ios::fixed);
    // cout.precision(3);
    int N;
    cin >> N;
    cout << "A student asked," << endl;
    PrintScript(0, N);
    return 0;
}