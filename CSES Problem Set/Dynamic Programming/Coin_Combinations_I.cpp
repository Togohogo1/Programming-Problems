#include <bits/stdc++.h>

using namespace std;

const int MM = 1e6+2, MOD = 1e9+7;
int n, x, arr[MM], dp[MM];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> x;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        dp[arr[i]] = 1;
    }

    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= arr[j]) {
                dp[i] += dp[i-arr[j]];
                dp[i] %= MOD;
            }
        }
    }

    cout << dp[x] << '\n';
}
