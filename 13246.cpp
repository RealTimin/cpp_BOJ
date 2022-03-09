// URL: https://www.acmicpc.net/problem/13246
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define endl '\n'
#define MOD 1000

ll N, B;
vvi I, O;

vvi MatrixAdd(vvi &X, vvi &Y) {
    vvi res(N, vi(N, 0));
    REP(i, 0, N) {
        REP(j, 0, N) {
            res[i][j] += X[i][j] + Y[i][j];
            res[i][j] %= MOD;
        }
    }
    return res;
}

vvi MatrixMul(vvi &X, vvi &Y) {
    int temp;
    vvi res(N, vi(N, 0));
    REP(i, 0, N) {
        REP(j, 0, N) {
            temp = 0;
            REP(k, 0, N) {
                temp += X[i][k] * Y[k][j];
                temp %= MOD;
            }
            res[i][j] = temp;
        }
    }
    return res;
}

vvi MatrixExp(vvi &A, ll B) {
    if (B == 1) {
        return A;
    }

    if (B & 1 == 1) {
        vvi temp = MatrixExp(A, B / 2);
        vvi res = MatrixMul(temp, temp);
        temp = MatrixMul(res, A);
        return temp;
    } else {
        vvi temp = MatrixExp(A, B / 2);
        vvi res = MatrixMul(temp, temp);
        return res;
    }
}

vvi Calc(vvi &A, ll B) {
    if (B == 1) {
        return MatrixAdd(A, O);
    }
    if (B & 1 == 1) {
        vvi temp = MatrixExp(A, B / 2 + 1);
        vvi res = Calc(A, B / 2);
        vvi ttemp = temp;
        ttemp = MatrixAdd(ttemp, I);
        res = MatrixMul(res, ttemp);
        res = MatrixAdd(res, temp);
        return res;
    } else {
        vvi temp = MatrixExp(A, B / 2);
        vvi res = Calc(A, B / 2);
        temp = MatrixAdd(temp, I);
        res = MatrixMul(res, temp);
        return res;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout.setf(ios::fixed);
    // cout.precision(3);
    cin >> N >> B;
    vvi A(N, vi(N, 0));
    O.assign(N, vi(N, 0));

    I.assign(N, vi(N, 0));
    REP(i, 0, N) { I[i][i] = 1; }
    REP(i, 0, N) {
        REP(j, 0, N) { cin >> A[i][j]; }
    }
    vvi res = Calc(A, B);
    REP(i, 0, N) {
        REP(j, 0, N) { cout << res[i][j] << ' '; }
        cout << endl;
    }

    return 0;
}