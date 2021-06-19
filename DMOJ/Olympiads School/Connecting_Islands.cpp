#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int MM = 52;
int M, N, tIdx, vis[MM][MM], dist[MM][MM], dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
char grid[MM][MM];
map<char, deque<pii>> mpq;

// Assigning different letters to different islands
void letFill(int r, int c) {
    string lets = "ABC";
    deque<pii> q;

    q.push_back({r, c});
    mpq[lets[tIdx]].push_back({r, c});
    grid[r][c] = lets[tIdx];
    vis[r][c] = 1;

    while (!q.empty()) {
        int cr = q.front().first, cc = q.front().second;
        q.pop_front();

        for (int i = 0; i < 4; i++) {
            int nr = cr + dir[i][0], nc = cc + dir[i][1];

            if (nr < 0 || nr >= M || nc < 0 || nc >= N || vis[nr][nc] || grid[nr][nc] == '.')
                continue;

            vis[nr][nc] = 1;
            q.push_back({nr, nc});

            if (grid[nr][nc] == 'X') {
                grid[nr][nc] = lets[tIdx];
                mpq[lets[tIdx]].push_back({nr, nc});
            }
        }
    }
}

// Finding minimum distance between 2 islands
int minDist(char ed, deque<pii> q) {
    int tDis = 0;
    bool foundDis = false;
    vector<vector<int>> vis(MM, vector<int>(MM, 0));

    memset(dist, 0, sizeof(dist));

    for (auto i : q) {
        vis[i.first][i.second] = 1;
    }

    while (!q.empty()) {
        int cr = q.front().first, cc = q.front().second;
        q.pop_front();

        for (int i = 0; i < 4; i++) {
            int nr = cr + dir[i][0], nc = cc + dir[i][1];

            if (nr < 0 || nr >= M || nc < 0 || nc >= N || vis[nr][nc])
                continue;

            vis[nr][nc] = 1;
            q.push_back({nr, nc});
            dist[nr][nc] = dist[cr][cc] + 1;

            if (!foundDis && grid[nr][nc] == ed) {
                foundDis = true;
                tDis = dist[nr][nc];
            }
        }
    }

    return tDis;
}

// Combining 2 islands into 1 by filling in every shortest path between the 2
deque<pii> retrace(int ed, int tDis) {
    deque<pii> aux, fin;
    vector<vector<int>> vis(MM, vector<int>(MM, 0));

    for (auto i : mpq[ed]) {
        if (dist[i.first][i.second] == tDis) {
            aux.push_back({i.first, i.second});
            fin.push_back({i.first, i.second});
        }
    }

    while (!aux.empty()) {
        int cr = aux.front().first, cc = aux.front().second;
        aux.pop_front();

        for (int i = 0; i < 4; i++) {
            int nr = cr + dir[i][0], nc = cc + dir[i][1];

            if (nr < 0 || nr >= M || nc < 0 || nc >= N || vis[nr][nc])
                continue;

            if (dist[nr][nc] == dist[cr][cc] - 1 || dist[nr][nc] == 0) {
                aux.push_back({nr, nc});
                fin.push_back({nr, nc});
                vis[nr][nc] = 1;
            }
        }
    }

    return fin;
}

int findAns(char st, char ed1, char ed2) {
    int tDis = minDist(ed1, mpq[st]);
    deque<pii> fin = retrace(ed1, tDis);
    tDis = tDis + minDist(ed2, fin) - 2;

    return tDis;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> M >> N;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (!vis[i][j] && grid[i][j] == 'X') {
                letFill(i, j);
                tIdx++;
            }
        }
    }

    int a = findAns('A', 'B', 'C'), b = findAns('B', 'A', 'C'), c = findAns('C', 'A', 'B');
    cout << min(a, min(b, c)) << '\n';
}
