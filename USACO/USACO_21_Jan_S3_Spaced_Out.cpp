#include <bits/stdc++.h>

using namespace std;

const int M = 1000;
int N, ans1, ans2, grid[M][M];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    // Checkboard vertically
    for (int i = 0; i < N; i++) {
        int tmp1 = 0, tmp2 = 0;

        for (int j = 0; j < N; j += 2) {
            tmp1 += grid[i][j];
            tmp2 += grid[i][j+1];
        }

        ans1 += max(tmp1, tmp2);
    }

    // Checkerboard vertically
    for (int i = 0; i < N; i++) {
        int tmp1 = 0, tmp2 = 0;

        for (int j = 0; j < N; j += 2) {
            tmp1 += grid[j][i];
            tmp2 += grid[j+1][i];
        }

        ans2 += max(tmp1, tmp2);
    }

    cout << max(ans1, ans2) << '\n';
}
