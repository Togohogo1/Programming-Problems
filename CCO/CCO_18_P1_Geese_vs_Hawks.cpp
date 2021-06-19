#include <bits/stdc++.h>

using namespace std;

const int M = 1002;
int N, vh[M], vg[M], dp[M][M];
string H, G;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> H;

    for (int i = 1; i <= N; i++) {
        cin >> vh[i];
    }

    cin >> G;

    for (int i = 1; i <= N; i++) {
        cin >> vg[i];
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if ((H[i-1] == 'W' && G[j-1] == 'L' && vh[i] > vg[j]) || (H[i-1] == 'L' && G[j-1] == 'W' && vh[i] < vg[j]))
                dp[i][j] = dp[i-1][j-1] + vh[i] + vg[j];

            dp[i][j] = max(dp[i][j], max(dp[i][j-1], dp[i-1][j]));
        }
    }

    cout << dp[N][N] << '\n';
}
