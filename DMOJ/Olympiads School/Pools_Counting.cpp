#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int MM = 102;
int N, M, K, ans, vis[MM][MM], dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
char grid[MM][MM];
vector<pii> water;
queue<pii> q;

void bfs(int r, int c) {
    q.push({r, c});
    vis[r][c] = 1;

    while (!q.empty()) {
        int cr = q.front().first, cc = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = cr + dir[i][0], nc = cc + dir[i][1];

            if (nr < 0 || nr >= N || nc < 0 || nc >= M || vis[nr][nc] || grid[nr][nc] == '.')
                continue;

            q.push({nr, nc});
            vis[nr][nc] = 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M >> K;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            grid[i][j] = '.';
        }
    }

    for (int i = 0, r, c; i < K; i++) {
        cin >> r >> c;
        grid[r-1][c-1] = 'W';
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!vis[i][j] && grid[i][j] == 'W') {
                ans++;
                bfs(i, j);
            }
        }
    }

    cout << ans << '\n';
}
