#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll M1 = 102, M2 = 1002, INF = 1e18;
ll N, W, ans, w[M1], v[M1], dp[M1][M2*M1];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> W;

    for (int i = 1; i <= N; i++) {
        cin >> w[i] >> v[i];
    }

    for (int i = 1; i < M2*M1; i++) {
        dp[0][i] = INF;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j < M2*M1; j++) {
            if (j - v[i] < 0)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = min(dp[i-1][j], dp[i-1][j-v[i]]+w[i]);
        }
    }

    for (int i = 1; i < M2*M1; i++) {
        if (dp[N][i] <= W)
            ans = i;
    }

    cout << ans << '\n';
}
