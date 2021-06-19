#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1e9+7;
ll N, K, T, C, ans;

struct matrix {
    vector<vector<ll>> data;

    matrix(int sz) {
        data.resize(sz, vector<ll>(sz, 0));
    }

    void identity() {
        for (int i = 0; i < data.size(); i++) {
            data[i][i] = 1;
        }
    }
};

matrix mult(matrix a, matrix b) {
    int n = a.data.size();
    matrix ans(n);

    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            for (int j = 0; j < n; j++) {
                ans.data[i][j] = (ans.data[i][j] + a.data[i][k]*b.data[k][j]) % MOD;
            }
        }
    }

    return ans;
}

matrix quick_pow(matrix a, ll exp) {
    matrix ans(a.data.size());
    ans.identity();

    while (exp > 0) {
        if (exp % 2 != 0)
            ans = mult(ans, a);

        a = mult(a, a);
        exp /= 2;
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> K >> T >> C;

    matrix x(T+1);

    x.data[T][T] = 1;
    x.data[0][T] = K;

    for (int i = 1; i <= T; i++) {
        x.data[i][i-1] = 1;
    }

    x = quick_pow(x, N-1);
    ans = 2*C*x.data[T][T] % MOD;

    for (int i = 0; i < T; i++) {
        ans = (ans + 1*C*x.data[i][T]%MOD) % MOD;
    }

    cout << ans << '\n';
}
