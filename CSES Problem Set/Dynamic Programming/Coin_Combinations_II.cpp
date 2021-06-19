#include <bits/stdc++.h>

using namespace std;

const int M = 1e6+2, MOD = 1e9+7;
int n, x, arr[M], dp[102][M];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> x;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // dp[i][j] = number of ways to obtain sum j using first i items
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= x; j++) {
            // Originally don't pick item i
            dp[i][j] = dp[i-1][j];

            // Pick item i and add to list of items if it can be picked
            if (j - arr[i-1] >= 0) {
                dp[i][j] += dp[i][j-arr[i-1]];
                dp[i][j] %= MOD;
            }
        }
    }

    cout << dp[n][x] << '\n';
}
