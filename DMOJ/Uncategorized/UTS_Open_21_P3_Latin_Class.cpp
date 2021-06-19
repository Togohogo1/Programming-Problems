#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll M = 1e5+2, MOD = 1e9+7;
ll N, cMax, tmp = 1, dp[M];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    for (ll i = 0, h; i < N; i++) {
        cin >> h;
        cMax = max(cMax, h);

        if (h < cMax) {
            tmp++;
            dp[i] = dp[i-1];
        } else {
            dp[i] = (i == 0 ? 1 : dp[i-tmp]*(tmp+1) % MOD);
            tmp = 1;
        }
    }

    cout << dp[N-1] << '\n';
}
