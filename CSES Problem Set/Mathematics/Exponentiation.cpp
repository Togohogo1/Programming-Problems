#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1e9+7;
int n, a, b;

ll fpow(int base, int exp) {
    if (!exp)
        return 1;

    ll t = fpow(base, exp/2);
    t = t*t % MOD;

    if (exp & 1)
        return t*base % MOD;

    return t;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        cout << fpow(a, b) << '\n';
    }
}
