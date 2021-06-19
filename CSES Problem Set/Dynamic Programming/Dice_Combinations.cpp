#include <bits/stdc++.h>

using namespace std;

const int M = 1e6+2, MOD = 1e9+7;
int n, dp[M];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    dp[0] = 1;

    for (int i = 0; i < M; i++) {
        for (int j = 1; j <= 6; j++) {
            if (j <= i) {
                dp[i] += dp[i-j];
                dp[i] %= MOD;
            }
        }
    }

    cout << dp[n] << '\n';
}
