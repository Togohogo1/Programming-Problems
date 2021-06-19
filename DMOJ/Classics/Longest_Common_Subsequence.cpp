#include <bits/stdc++.h>

using namespace std;

const int MM = 1002;
int N, M, t0, t1, aN[MM], aM[MM], dp[MM];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> aN[i];
    }

    for (int i = 1; i <= M; i++) {
        cin >> aM[i];
    }

    if (N > M) {
        swap(N, M);
        swap(aN, aM);
    }

    for (int i = 1; i <= N; i++) {
        t0 = dp[0];

        for (int j = 1; j <= M; j++) {
            t1 = dp[j];

            if (aN[i] == aM[j])
                dp[j] = t0 + 1;
            else
                dp[j] = max(dp[j], dp[j-1]);

            t0 = t1;
        }
    }

    cout << dp[M] << '\n';
}
