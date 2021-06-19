#include <bits/stdc++.h>

using namespace std;

const int M = 702;
int N, tot, ans, tasks[M], dp[M*M];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> tasks[i];
        tot += tasks[i];
    }

    dp[0] = 1;
    ans = tot;

    for (int i = 1; i <= N; i++) {
        for (int j = tot; j >= 1; j--) {
            if (j - tasks[i] >= 0)
                dp[j] |= dp[j-tasks[i]];
        }
    }

    for (int i = 1; i <= tot; i++) {
        if (dp[i])
            ans = min(ans, abs(2*i-tot));
    }

    cout << ans << '\n';
}
