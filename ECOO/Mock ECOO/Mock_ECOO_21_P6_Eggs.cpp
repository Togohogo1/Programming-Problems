#include <bits/stdc++.h>

using namespace std;

const int MM = 1002, MOD = 1e9+7;
int N, M, K, grid[MM][MM];
vector<pair<int, int>> rows[MM], cols[MM];
char D;

bool egged(int r, int c, int step) {
    for (auto i : rows[r]) {
        if (i.second < 0) {
            if (step == 0)
                return i.first >= c;
            else if (i.first + (step-1)*i.second >= c)
                return true;
        } else {
            if (step == 0)
                return i.first <= c;
            else if (i.first + (step-1)*i.second <= c)
                return true;
        }
    }

    for (auto i : cols[c]) {
        if (i.second < 0) {
            if (step == 0)
                return i.first >= r;
            else if (i.first + (step-1)*i.second >= r)
                return true;
        } else {
            if (step == 0)
                return i.first <= r;
            else if (i.first + (step-1)*i.second <= r)
                return true;
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M >> K;

    for (int i = 0, R, C, S; i < K; i++) {
        cin >> R >> C >> S >> D;

        if (D == 'D')
            cols[C].push_back({R, S});
        else if (D == 'U')
            cols[C].push_back({R, -S});
        else if (D == 'L')
            rows[R].push_back({C, -S});
        else if (D == 'R')
            rows[R].push_back({C, S});
    }

    grid[1][1] = 1;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            int step = i + j - 2;

            if (egged(i, j, step)) {
                grid[i][j] = 0;
            } else {
                if (grid[i][j-1] != 0) {
                    grid[i][j] += grid[i][j-1];
                } if (grid[i-1][j] != 0) {
                    grid[i][j] += grid[i-1][j];
                }
            }

            grid[i][j] %= MOD;
        }
    }

    cout << grid[N][M] << '\n';
}
