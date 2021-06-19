#include<bits/stdc++.h>

using namespace std;

const int M = 102;
int N, cycle, vis[M], dist[M];
vector<int> adj[M];

void dfs(int u) {
    if (cycle != 0)
        return;

    vis[u] = 1;

    for (int v : adj[u]) {
        if (vis[v] == 1) {
            cycle = dist[u] - dist[v] + 1;
            return;
        } else if (vis[v] == 0) {
            dist[v] = dist[u] + 1;
            dfs(v);
        }
    }

    vis[u] = 2;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    for (int i = 0; i < 5; i++) {
        cin >> N;

        memset(vis, 0, sizeof(vis));
        memset(dist, 0, sizeof(dist));

        for (auto &v : adj) {
            v.clear();
        }

        for (int i = 0, u, v; i < N; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }

        cycle = 0;
        dfs(1);
        cout << cycle << '\n';
    }
}
