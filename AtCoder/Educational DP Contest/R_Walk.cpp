#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<vector<ll>> mat;

const ll M = 52, MOD = 1e9+7;
ll N, K, ans;
mat adj(M, vector<ll>(M, 0));

mat matmult(mat a, mat b) {
    mat ret(M, vector<ll>(M, 0));

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < M; k++) {
                ret[i][j] = (ret[i][j] + a[i][k]*b[k][j]) % MOD;
            }
        }
    }

    return ret;
}

mat matpow(mat a, ll exp) {
    if (exp == 1)
        return a;

    mat tmp = matpow(a, exp/2);
    tmp = matmult(tmp, tmp);

    if (exp & 1)
        return matmult(tmp, a);

    return tmp;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> adj[i][j];
        }
    }

    adj = matpow(adj, K);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            ans = (ans+adj[i][j]) % MOD;
        }
    }

    cout << ans << '\n';
}
