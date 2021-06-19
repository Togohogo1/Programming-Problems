#include <bits/stdc++.h>

using namespace std;

const int M1 = 102, M2 = 1e6+2;
int n, x, coin[M1], dp[M2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> x;
    fill(dp, dp+M2, M2);

    for (int i = 1; i <= n; i++) {
        cin >> coin[i];
        dp[coin[i]] = 1;
    }

    for (int i = 1; i <= x; i++) {
        for (int j = 1; j <= n; j++) {
            if (coin[j] < i)
                dp[i] = min(dp[i], 1+dp[i-coin[j]]);
        }
    }

    cout << (dp[x] != M2 ? dp[x] : -1) << '\n';
}
