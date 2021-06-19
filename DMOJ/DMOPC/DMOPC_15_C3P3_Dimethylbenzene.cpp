#include<bits/stdc++.h>

using namespace std;

int N, M, u, v, cycle, dis[22], vis[22];
bool has6 = false;
vector<int> adj[22];

void dfs(int u) {
    vis[u] = 1;

    for (int v : adj[u]) {
        if (vis[v] == 1) {
            if (dis[u] - dis[v] + 1 == 6) {
                has6 = true;
                return;
            }
        } else if (vis[v] == 0) {
            dis[v] = dis[u] + 1;
            dfs(v);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= N; i++) {
        dfs(i);
        memset(dis, 0, sizeof(dis));
        memset(vis, 0, sizeof(vis));
    }

    cout << (has6 ? "YES\n" : "NO\n");
}
