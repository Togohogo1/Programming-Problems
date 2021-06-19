#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e10;
long long t, ans;

long long mod(long long a, long long b) {
    return (a%MOD * b%MOD) % MOD;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    for (int i = 1; i <= 10; i++) {
        t = i;

        for (int j = 1; j < i; j++) {
            t = mod(t, i);
        }

        ans += t;
    }

    cout << ans % MOD << '\n';
}
