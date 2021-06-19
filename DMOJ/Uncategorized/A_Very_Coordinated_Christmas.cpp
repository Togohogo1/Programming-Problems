#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int MM = 1002;
int N, M, sr, sc, er, ec, tDist, dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
char grid[MM][MM];

bool bfs(int r, int c) {
    int tmp = 0;
    vector<vector<int>> vis(MM, vector<int>(MM, 0)), dist(MM, vector<int>(MM, 0));
    queue<pii> q;

    q.push({r, c});
    vis[r][c] = 1;

    while (!q.empty()) {
        int cr = q.front().first, cc = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = cr + dir[i][0], nc = cc + dir[i][1];

            if (nr < 0 || nr >= N || nc < 0 || nc >= M || vis[nr][nc] || grid[nr][nc] == '#')
                continue;

            q.push({nr, nc});
            vis[nr][nc] = 1;
            dist[nr][nc] = dist[cr][cc] + 1;

            if (grid[nr][nc] == 'P') {
                tDist += dist[nr][nc];
                tmp = dist[nr][nc];
                break;
            }
        }
    }

    return tmp;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];

            if (grid[i][j] == 'O') {
                sr = i;
                sc = j;
            } else if (grid[i][j] == 'X') {
                er = i;
                ec = j;
            }
        }
    }

    if (bfs(sr, sc) == 0) {
        cout << -1 << '\n';
        return 0;
    }

    if (bfs(er, ec) == 0) {
        cout << -1 << '\n';
        return 0;
    }

    cout << tDist << '\n';
}
