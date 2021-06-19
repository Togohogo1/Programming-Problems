#include <bits/stdc++.h>

using namespace std;

const int M = 500;
int a, b, dp[M][M];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> a >> b;

    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            if (i != j) {
                dp[i][j] = M;

                for (int k = i - 1; k > 0; k--) {
                    dp[i][j] = min(dp[i][j], 1+dp[k][j]+dp[i-k][j]);
                }

                for (int k = j - 1; k > 0; k--) {
                    dp[i][j] = min(dp[i][j], 1+dp[i][k]+dp[i][j-k]);
                }
            }
        }
    }

    cout << dp[a][b] << '\n';
}
