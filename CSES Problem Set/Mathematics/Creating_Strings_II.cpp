#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll M = 1e6+2, MOD = 1e9+7;
ll num = 1, denom = 1, fact[M];
string n;
map<char, ll> frq;

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

    cin >> n;
    fact[1] = 1;

    for (int i = 2; i <= n.size(); i++) {
        fact[i] = (i*fact[i-1]) % MOD;
    }

    for (char i : n) {
        frq[i]++;
    }

    for (auto i : frq) {
        denom *= fact[i.second];
        denom %= MOD;
    }

    // Fermat's little and modular inverse
    cout << (fact[n.size()]*fpow(denom, MOD-2)) % MOD << '\n';
}
