#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1e9+7;
ll R, C;

ll fpow(ll a, ll n) {
    if (n == 0)
        return 1;

    ll t = fpow(a, n/2);
    t = t*t % MOD;

    if (n & 1)
        return a*t % MOD;

    return t;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> R >> C;
    ll a = (R-1)*(C-1);
    cout << fpow(2, a) << '\n';
}
