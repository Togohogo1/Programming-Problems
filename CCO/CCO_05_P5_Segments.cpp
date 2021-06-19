#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MM = 2e4+2;
ll n, dp[MM][2], pt[MM][2];

ll dis(int a, int b, int c) {
    return abs(a-b) + abs(b-c);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        // 0 -> L, 1 -> R
        cin >> pt[i][0] >> pt[i][1];
    }

    // First row
    dp[1][0] = n + pt[1][1] - pt[1][0] - 1;
    dp[1][1] = pt[1][1] - 1;

    // dp[i][L/R] = min dist to seg i ending at L/R endpoint
    for (int i = 2; i <= n; i++) {
        dp[i][0] = 1 + min(dp[i-1][0]+dis(pt[i-1][0], pt[i][1], pt[i][0]), dp[i-1][1]+dis(pt[i-1][1], pt[i][1], pt[i][0]));
        dp[i][1] = 1 + min(dp[i-1][0]+dis(pt[i-1][0], pt[i][0], pt[i][1]), dp[i-1][1]+dis(pt[i-1][1], pt[i][0], pt[i][1]));
    }

    cout << min(dp[n][0]+n-pt[n][0], dp[n][1]+n-pt[n][1]) << '\n';
}
