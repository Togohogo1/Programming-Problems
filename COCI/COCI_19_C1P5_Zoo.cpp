#include<bits/stdc++.h>

using namespace std;

const int M = 1002;
int R, C, ans = 0, dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
char grid[M][M];
bool vis[M][M];
queue<pair<int, int>> q[2]; // Array of 2 queues

void bfs() {
    while(!q[0].empty()) {
        int cr = q[0].front().first, cc = q[0].front().second;
        q[0].pop();

        for (int i = 0; i < 4; i++) {
            int nr = cr+dir[i][0], nc = cc+dir[i][1];

            if (nr < 1 || nr > R || nc < 1 || nc > C || vis[nr][nc] || grid[nr][nc] == '*')
                continue;

            // Adjacent to same animal
            if (grid[nr][nc] == grid[cr][cc]) {
                q[0].push({nr, nc});
                vis[nr][nc] = true;

            // Adjacent to new animal
            } else {
                q[1].push({nr, nc});
                vis[nr][nc] = true;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> R >> C;

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            cin >> grid[i][j];
        }
    }

    // Top right animal first to reach finish
    q[0].push({1, 1});
    vis[1][1] = true;

    while (true) {
        ans++;
        bfs();

        if (q[1].empty())
            break;

        // O(1), only swapping reference
        swap(q[0], q[1]);
    }

    cout << ans << '\n';
}
