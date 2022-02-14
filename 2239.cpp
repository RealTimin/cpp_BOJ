// URL: https://www.acmicpc.net/problem/2239
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define endl '\n'

// DFS and backtracking

int board[9][9] = {0};

bool CheckBoard(int r, int c) {
  vi check(10, 0);
  REP(j, 0, 9) { check[board[r][j]]++; }
  REP(k, 1, 10) {
    if (check[k] > 1) {
      return false;
    }
  }
  check.assign(10, 0);
  REP(i, 0, 9) { check[board[i][c]]++; }
  REP(k, 1, 10) {
    if (check[k] > 1) {
      return false;
    }
  }
  check.assign(10, 0);
  int sr = r - (r % 3);
  int sc = c - (c % 3);
  REP(i, 0, 3) {
    REP(j, 0, 3) { check[board[sr + i][sc + j]]++; }
  }
  REP(k, 1, 10) {
    if (check[k] > 1) {
      return false;
    }
  }
  return true;
}

bool FillBoard(int r, int c) {
  int nr = r + (c + 1) / 9;
  int nc = (c + 1) % 9;
  if (r == 9 && c == 0) {
    return true;
  } else if (board[r][c] != 0) {
    if (!CheckBoard(r, c)) return false;
    return FillBoard(nr, nc);
  } else {
    bool checked = false;
    int num = 0;
    while (!checked && num < 9) {
      num++;
      board[r][c] = num;
      if (!CheckBoard(r, c)) continue;
      checked = FillBoard(nr, nc);
    }
    if (!checked) board[r][c] = 0;
    return checked;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  // cout.setf(ios::fixed);
  // cout.precision(3);
  // int T;
  // cin >> T;
  string s;
  // int num;
  REP(i, 0, 9) {
    cin >> s;
    REP(j, 0, 9) {
      // cin >> num;
      // board[i][j] = num;
      board[i][j] = s[j] - '0';
    }
  }
  FillBoard(0, 0);
  REP(i, 0, 9) {
    REP(j, 0, 9) {
      // cout << board[i][j] << ' ';
      cout << board[i][j];
    }
    cout << endl;
  }

  return 0;
}