#include<bits/stdc++.h>

using namespace std;

const int M = 1002, MOD = 1e9+7;
int n, dp[M];
char cell;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cell;
            dp[j] = (cell == '.' ? dp[j] + dp[j-1] : 0) % MOD;
        }
    }

    cout << dp[n-1] << '\n';
}
