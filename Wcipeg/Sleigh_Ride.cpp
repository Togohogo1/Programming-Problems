#include<bits/stdc++.h>

using namespace std;

const int M = 1e5;
int N, ans, mx, vis[M], dis[M];
vector<pair<int, int>> adj[M];
queue<int> q;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    for (int i = 1, u, v, w; i <= N; i++) {
        cin >> u >> v >> w;
        ans += 2*w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    q.push(0);
    dis[0] = 0;
    vis[0] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        mx = max(mx, dis[u]);

        for (auto e : adj[u]) {
            int v = e.first, w = e.second;

            if (!vis[v]) {
                q.push(v);
                vis[v] = true;
                dis[v] = dis[u] + w;
            }
        }
    }

    cout << ans - mx << '\n';
}
