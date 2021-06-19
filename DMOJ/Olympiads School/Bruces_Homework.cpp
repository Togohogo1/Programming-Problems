#include <bits/stdc++.h>

using namespace std;

const int MM = 2e4+2;
int N, M, T, cost[MM];
double fre, val[MM], dp[MM];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M >> T;

    for (int i = 1; i <= N; i++) {
        cin >> cost[i];
    }

    for (int i = 0, A; i < M; i++) {
        cin >> A;

        if (A == 0)
            fre++;

        for (int j = 1, x; j <= A; j++) {
            cin >> x;
            val[x] += 1.0/A;
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = T; j >= cost[i]; j--) {
            dp[j] = max(dp[j], dp[j-cost[i]]+val[i]);
        }
    }

    cout << setprecision(3) << dp[T] + fre << '\n';
}
