#include <bits/stdc++.h>

using namespace std;

const int M = 1002;
int N, cycle, vis[M], adj[M][M];

void dfs(int u) {
    vis[u] = 1;

    for (int v = 0; v < M; v++) {
        if (adj[u][v]) {
            if (vis[v] == 1) {
                cycle = true;
                return;
            } else if (vis[v] == 0)
                dfs(v);
        }
    }

    vis[u] = 2;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> adj[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        dfs(i);
    }

    cout << (cycle ? "NO\n" : "YES\n");
}
