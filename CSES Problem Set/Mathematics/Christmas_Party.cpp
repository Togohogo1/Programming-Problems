#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll M = 2e6+2, MOD = 1e9+7;
ll n, deArr[M];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    deArr[1] = 0;
    deArr[2] = 1;

    cin >> n;

    // Derangements formula
    for (int i = 3; i <= n; i++) {
        deArr[i] = (i-1)*(deArr[i-1]+deArr[i-2]) % MOD;
    }

    cout << deArr[n] << '\n';
}
