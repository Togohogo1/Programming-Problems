#include <bits/stdc++.h>

using namespace std;

const int MM = 302;
int M, U, R;
int V[MM], T[MM], F[MM], dp[MM][MM];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> M >> U >> R;

    for (int i = 1; i <= R; i++) {
        cin >> V[i] >> T[i] >> F[i];
    }

    for (int i = 1; i <= R; i++) {
        for (int f = U; f >= 0; f--) {
            for (int t = M; t >= 0; t--) {
                if (f - F[i] >= 0 && t - T[i] >= 0)
                    dp[f][t] = max(dp[f][t], dp[f-F[i]][t-T[i]]+V[i]);
            }
        }
    }

    cout << dp[U][M] << '\n';
}
