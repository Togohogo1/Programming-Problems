#include <bits/stdc++.h>

using namespace std;

const int M = 1e5+2;
int n, x, pre, h[M], s[M], dp[M];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> x;

    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }

    for (int i = 1; i <= n; i++) {
        // Loop backwards for 0-1 knapsack
        for (int j = x; j >= 0; j--) {
            if (j - h[i] >= 0)
                dp[j] = max(dp[j], dp[j-h[i]]+s[i]);
        }
    }

    cout << dp[x] << '\n';
}
