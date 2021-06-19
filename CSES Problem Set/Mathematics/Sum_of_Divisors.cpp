#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1e9+7;
ll n, ans, tmp;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;

    for (ll i = 1; i*i <= n; i++) {
        ll A = ((1+n/(i+1))*i) % MOD, t = (n/i-n/(i+1)) % MOD;

        if (t & 1)
            ans += ((t-1)/2) * ((2*A+(t-2)*i) % MOD) + (n/i)*i;
        else
            ans += (t/2) * ((2*A+(t-1)*i) % MOD);

        ans %= MOD;
        tmp = n/i;
    }

    for (ll i = tmp-1; i; i--) {
        ans += i*(n/i);
        ans %= MOD;
    }

    cout << ans << "   \n";
}
