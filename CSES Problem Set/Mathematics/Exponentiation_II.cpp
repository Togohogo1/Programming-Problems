#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1e9+7;
int n, a, b, c;

ll fpow(int base, int exp, int mod) {
    if (!exp)
        return 1;

    ll t = fpow(base, exp/2, mod);
    t = t*t % mod;

    if (exp & 1)
        return t*base % mod;

    return t;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        cout << fpow(a, fpow(b, c, MOD-1), MOD) << '\n';
    }
}
