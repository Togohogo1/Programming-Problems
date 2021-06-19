#include <bits/stdc++.h>

using namespace std;

const int M = 1002;
int N, T, V[M], H[M], dp[M];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> T;

    for (int i = 1; i <= N; i++) {
        cin >> V[i] >> H[i];
    }

    for (int i = 1; i <= N; i++) {
        for (int j = T; j >= 0; j--) {
            if (j - H[i] >= 0)
                dp[j] = max(dp[j], dp[j-H[i]]+V[i]);
        }
    }

    cout << dp[T] << '\n';
}
