#include <bits/stdc++.h>

using namespace std;

const int M = 500002;
int N, Q, a, b, arr[M], maxR[M], maxL[M], psaR[11][M], psaL[11][M];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> Q;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        maxR[i] = max(maxR[i-1], arr[i]);
        psaR[arr[i]][i]++;
    }

    for (int i = N; i > 0; i--) {
        maxL[i] = max(maxL[i+1], arr[i]);
        psaL[arr[i]][i]++;
    }

    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= N; j++) {
            psaR[i][j] += psaR[i][j-1];
            psaL[i][N-j+1] += psaL[i][N-j+2];
        }
    }

    for (int i = 0; i < Q; i++) {
        cin >> a >> b;
        int m = max(maxR[a-1], maxL[b+1]);
        cout << m << ' ' << psaR[m][a-1] + psaL[m][b+1] << '\n';
    }
}
