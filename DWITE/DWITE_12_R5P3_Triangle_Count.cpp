#include <bits/stdc++.h>

using namespace std;

const int M = 2002;
int N, ans, dp[M][M];
char grid[M][M];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    for (int i = 0; i < 5; i++) {
        memset(dp, 0, sizeof(dp));
        memset(grid, '\0', sizeof(grid));
        ans = 0;

        cin >> N;

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                cin >> grid[i][j];
            }
        }

        for (int i = N; i > 0; i--) {
            for (int j = 1; j <= N; j++) {
                if (grid[i][j] == '#') {
                    dp[i][j] = min(dp[i+1][j], min(dp[i+1][j-1], dp[i+1][j+1])) + 1;
                    ans += dp[i][j];
                }
            }
        }

        cout << ans << '\n';
    }
}
