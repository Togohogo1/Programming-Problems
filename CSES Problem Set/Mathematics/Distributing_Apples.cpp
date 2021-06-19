#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll M = 2e6+2, MOD = 1e9+7;
ll n, m, tmp, m1, m2, fact[M];

ll fpow(ll b, ll e) {
    if (!e)
        return 1;

    ll t = fpow(b, e/2);
    t = t*t % MOD;

    if (e & 1)
        t = t*b % MOD;

    return t;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    fact[1] = 1;

    for (ll i = 2; i < M; i++) {
        fact[i] = (i*fact[i-1]) % MOD;
    }

    cin >> n >> m;

    m1 = fpow(fact[m], MOD-2);
    m2 = fpow(fact[n-1], MOD-2);
    tmp = (m1*m2) % MOD;

    cout << (n == 1 ? 1 : (fact[m+n-1]*tmp) % MOD) << '\n';
}
