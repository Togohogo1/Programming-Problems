#include <bits/stdc++.h>

using namespace std;

const int MM = 1002;
int n, m, rooms, vis[MM][MM];
char grid[MM][MM];

void bfs(int r, int c) {
    int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    queue<pair<int, int>> q;

    vis[r][c] = 1;
    q.push({r, c});

    while (!q.empty()) {
        int cr = q.front().first, cc = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = cr + dir[i][0], nc = cc + dir[i][1];

            if (nr < 0 || nr >= n || nc < 0 || nc >= m || grid[nr][nc] == '#' || vis[nr][nc])
                continue;

            vis[nr][nc] = 1;
            q.push({nr, nc});
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j] && grid[i][j] == '.') {
                bfs(i, j);
                rooms++;
            }
        }
    }

    cout << rooms << '\n';
}
