#include <bits/stdc++.h>

using namespace std;

const int M = 4;
int n, m, sr, sc, vis[M][M], dist[M][M], dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
char grid[M][M];
queue<pair<int, int>> dq;

void bfs(int sr, int sc) {
    vis[sr][sc] = true;
    dq.push({sr, sc});

    while (!dq.empty()) {
        int cr = dq.front().first, cc = dq.front().second;
        dq.pop();

        for (int i = 0; i < 4; i++) {
            int nr = cr+dir[i][0], nc = cc+dir[i][1];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                if (grid[nr][nc] == 'e') {
                    cout << dist[cr][cc] << '\n';
                    return;
                } else if (grid[nr][nc] == 'X' || vis[nr][nc])
                    continue;

                vis[nr][nc] = true;
                dist[nr][nc] = dist[cr][cc] + 1;
                dq.push({nr, nc});
            }
        }
    }

    cout << -1 << endl;
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            cin >> grid[r][c];

            if (grid[r][c] == 's') {
                sr = r;
                sc = c;
            }
        }
    }

    bfs(sr, sc);
}
