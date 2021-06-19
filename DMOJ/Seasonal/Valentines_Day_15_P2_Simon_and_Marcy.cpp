#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MM = 1002;
ll C, M, w[MM], v[MM], dp[MM];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> C >> M;

    for (int i = 1; i <= C; i++) {
        cin >> v[i] >> w[i];
    }

    for (int i = 1; i <= C; i++) {
        for (int j = MM - 1; j >= 0; j--) {
            if (j - w[i] >= 0)
                dp[j] = max(dp[j], dp[j-w[i]]+v[i]);
        }
    }

    cout << dp[M] << '\n';
}
