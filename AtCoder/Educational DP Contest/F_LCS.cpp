#include <bits/stdc++.h>

using namespace std;

const int M = 3002;
int ss, ts, dp[M][M];
string s, t, ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> s >> t;
    ss = s.size(), ts = t.size();

    for (int i = 1; i <= ss; i++) {
        for (int j = 1; j <= ts; j++) {
            if (s[i-1] == t[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }

    while (ss && ts) {
        if (dp[ss][ts] == dp[ss-1][ts])
            ss--;
        else if (dp[ss][ts] == dp[ss][ts-1])
            ts--;
        else {
            ss--;
            ts--;
        }

        if (s[ss] == t[ts])
            ans += s[ss];
    }

    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
}
