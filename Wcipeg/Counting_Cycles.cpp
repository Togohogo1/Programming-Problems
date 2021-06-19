#include<bits/stdc++.h>

using namespace std;

int N, cycles, adj[11][11], vis1[11], vis2[11];

void dfs(int u, int start) {
    vis1[u] = true;

    for (int v = 1; v <= N; v++) {
        if (adj[u][v]) {
            if (v == start)
                cycles++;
            else if (!vis1[v] && !vis2[v])
                dfs(v, start);
        }
    }

    vis1[u] = false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> adj[i][j];
        }
    }

    for (int i = 1; i <= N; i++) {
        dfs(i, i);
        vis2[i] = true;
    }

    cout << cycles << '\n';
}
