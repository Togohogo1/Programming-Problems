#include <bits/stdc++.h>

using namespace std;

const int M = 5002;
int dp[M][M];
string n, m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n.size(); i++) {
        dp[i][0] = dp[i-1][0] + 1;
    }

    for (int i = 1; i <= m.size(); i++) {
        dp[0][i] = dp[0][i-1] + 1;
    }

    for (int i = 1; i <= n.size(); i++) {
        for (int j = 1; j <= m.size(); j++) {
            dp[i][j] = min(dp[i-1][j-1]+(n[i-1]!=m[j-1]), min(dp[i][j-1]+1, dp[i-1][j]+1));
        }
    }

    cout << dp[n.size()][m.size()] << '\n';
}
