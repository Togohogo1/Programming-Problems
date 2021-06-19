#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1e9+7;

ll n, num = 1, num2 = 1, nod = 1, nod2 = 1, sod = 1, pod;
bool flag;

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

    for (ll i = 0, x, k; i < n; i++) {
        cin >> x >> k;

        // num, multipled out
        num = num*fpow(x, k) % MOD;

        if (k & 1 && !flag) {
            nod2 = nod2*(k+1)/2 % (MOD-1);
            flag = true;
        } else
            nod2 = nod2*(k+1) % (MOD-1);

        // sqrt(num)
        if (k % 2 == 0)
            num2 = num2*fpow(x, k/2) % MOD;

        // Number of divisors
        nod = nod*(k+1) % MOD;

        // Sum of divisors
        sod = sod*(fpow(x, k+1)-1) % MOD;
        sod = sod*fpow(x-1, MOD-2) % MOD;
    }

    // Product of divisors
    pod = fpow((flag ? num : num2), nod2);

    cout << nod << ' ' << sod << ' ' << pod << '\n';
}
