#include <bits/stdc++.h>

using namespace std;

const int MM = 1e4+5;
int N, M, ans;
bool grid[MM][MM];

void init() {
    for (int j = 1; j < MM; j++) {
        for (int i = 1; i < MM; i++) {
            grid[i][j] ^= grid[i][j-1] ^ grid[i-1][j] ^ grid[i-1][j-1];
        }
    }
}

void update(int r1, int c1, int r2, int c2) {
    grid[r1][c1] ^= 1;
    grid[r1][c2+1] ^= 1;
    grid[r2+1][c2+1] ^= 1;
    grid[r2+1][c1] ^= 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M;

    for (int i = 0, x, y, w, h; i < M; i++) {
        cin >> x >> y >> w >> h;
        update(x+1, y+1, x+w, y+h);
    }

    init();

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            ans += grid[i][j];
        }
    }

    cout << ans << '\n';
}
