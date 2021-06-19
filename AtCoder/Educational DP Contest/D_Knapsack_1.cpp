#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll M = 1e5+2;
ll N, W, w[M], v[M], dp[M];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> W;

    for (int i = 1; i <= N; i++) {
        cin >> w[i] >> v[i];
    }

    for (int i = 1; i <= N; i++) {
        for (int j = M - 1; j >= 0; j--) {
            if (j - w[i] >= 0)
                dp[j] = max(dp[j], dp[j-w[i]]+v[i]);
        }
    }

    cout << dp[W] << '\n';
}
