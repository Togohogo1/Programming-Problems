#include<bits/stdc++.h>

using namespace std;

const int M = 5e4+2, LOG=16;
int N, Q, mx[LOG][M], mi[LOG][M];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> Q;

    // Directly fill sparse table column 1
    for (int i = 1; i <= N; i++) {
        cin >> mx[0][i];
        mi[0][i] = mx[0][i];
    }

    for (int i = 1; i <= LOG; i++) {
        for (int j = 1; j+(1<<i)-1 <= N; j++) {
            // Filling the rest of the spase table
            mx[i][j] = max(mx[i-1][j], mx[i-1][j+(1<<(i-1))]);
            mi[i][j] = min(mi[i-1][j], mi[i-1][j+(1<<(i-1))]);
        }
    }

    for (int i = 1, x, y; i <= Q; i++) {
        cin >> x >> y;

        // Log2()
        int k = 31 - __builtin_clz(y-x+1);

        // Max query and min query
        cout << max(mx[k][x], mx[k][y-(1<<k)+1]) - min(mi[k][x], mi[k][y-(1<<k)+1]) << '\n';
    }
}
