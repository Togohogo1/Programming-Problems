#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int M = 1e5+2, MOD = 1e9+7;
ll n, m, ans, arr[M], dp[102][M];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    if(arr[1] == 0) {
        for (int i = 1; i <= m; i++) {
            dp[i][1] = 1;
        }
    } else
        dp[arr[1]][1] = 1;

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (arr[i] == 0 || arr[i] == j) {
                dp[j][i] += dp[j-1][i-1] + dp[j][i-1] + dp[j+1][i-1];
                dp[j][i] %= MOD;
            }
        }
    }

    if (arr[n] == 0) {
        for (int i = 1; i <= m; i++) {
            ans += dp[i][n];
            ans %= MOD;
        }
    } else
        ans = dp[arr[n]][n];

    cout << ans << '\n';
}
