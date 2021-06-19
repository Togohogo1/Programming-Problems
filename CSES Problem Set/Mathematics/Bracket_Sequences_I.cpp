#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int M = 1e6+2, MOD = 1e9+7;
ll n, num, dnom, ans, fact[M];

ll fpow(ll b, ll e) {
    if (!e)
        return 1;

    ll t = fpow(b, e/2);
    t = t*t % MOD;

    if (e & 1)
        return t*b % MOD;

    return t;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;

    if (n & 1) {
        cout << 0 << '\n';
        return 0;
    }

    fact[1] = 1;

    for (int i = 2; i <= n; i++) {
        fact[i] = i*fact[i-1] % MOD;
    }

    // Catalan numbers
    // Total sequences with n/2 ")" and n/2 "(" - illegal sequences
    // C(2n, n) - C(2n, n+1)
    num = fact[n];
    dnom = (fpow(fpow(fact[n/2], MOD-2), 2))*fpow(n/2+1, MOD-2) % MOD;

    cout << num*dnom % MOD << '\n';
}
