#include <bits/stdc++.h>

using namespace std;

const int M = 1e5+2;
int N, h[M], dp[M];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> h[i];
    }

    dp[1] = 0;
    dp[2] = abs(h[2]-h[1]);

    // dp[i] = min cost to jump to stone i
    for (int i = 3; i <= N; i++) {
        dp[i] = min(dp[i-1]+abs(h[i]-h[i-1]), dp[i-2]+abs(h[i]-h[i-2]));
    }

    cout << dp[N] << '\n';
}
