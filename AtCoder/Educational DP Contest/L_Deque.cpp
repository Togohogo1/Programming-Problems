#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll M = 3002;
ll N, arr[M], dp[M][M];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        dp[i][i] = arr[i];
    }

    // dp[l][r] = max of X - Y in the range [l, r]
    // Looping from dp[l][r] to dp[l][N] from l to 1
    for (int l = N - 1; l > 0; l--) {
        for (int r = l + 1; r <= N; r++) {
            dp[l][r] = max(dp[l][l]-dp[l+1][r], dp[r][r]-dp[l][r-1]);
        }
    }

    cout << dp[1][N] << '\n';
}
