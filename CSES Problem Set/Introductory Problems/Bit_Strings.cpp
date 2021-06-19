#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1e9+7;
ll n;

ll fpow(ll exp) {
    if (!exp)
        return 1;

    ll t = fpow(exp/2);
    t = t*t % MOD;

    if (exp & 1)
        return 2*t % MOD;

    return t;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    cout << fpow(n) << '\n';
}
