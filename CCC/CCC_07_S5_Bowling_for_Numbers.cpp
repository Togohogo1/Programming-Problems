#include <bits/stdc++.h>

using namespace std;

const int M = 30002;
int t, n, k, w, arr[M], psa[M], dp[502][M];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n >> k >> w;

        memset(dp, 0, sizeof(dp));
        memset(arr, 0, sizeof(arr));
        memset(psa, 0, sizeof(psa));

        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
            psa[i] = arr[i] + psa[i-1];
        }

        for (int i = 1; i <= k; i++) {
            for (int j = 1; j <= n; j++) {
                if (j - w < 1)
                    dp[i][j] = psa[j];
                else
                    dp[i][j] = max(dp[i-1][j-w]+psa[j]-psa[j-w], dp[i][j-1]);
            }
        }

        cout << dp[k][n] << '\n';
    }
}
