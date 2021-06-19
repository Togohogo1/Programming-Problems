#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

const int MM = 22;
int N, M, ans, grid[MM][MM], vis[MM][MM], dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
priority_queue<pair<int, pair<int, int>>> pq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    for (int i = 0; i < 5; i++) {
        cin >> N >> M;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> grid[i][j];

                if (i == 0 || i == N - 1 || j == 0 || j == M - 1) {
                    vis[i][j] = true;
                    pq.push({-grid[i][j], {i, j}});
                }
            }
        }

        while (!pq.empty()) {
            int cur = -pq.top().f, cr = pq.top().s.f, cc = pq.top().s.s;
            pq.pop();

            for (int i = 0; i < 4; i++) {
                int nr = cr + dir[i][0], nc = cc + dir[i][1];

                if (!vis[nr][nc] && nr >= 0 && nc >= 0 && nr < N && nc < M) {
                    if (cur - grid[nr][nc] > 0) {
                        ans += cur-grid[nr][nc];
                        pq.push({-cur, {nr, nc}});
                    } else
                        pq.push({-grid[nr][nc], {nr, nc}});

                    vis[nr][nc] = true;
                }
            }
        }

        cout << ans << '\n';

        memset(vis, 0, sizeof(vis));
        ans = 0;
    }
}
