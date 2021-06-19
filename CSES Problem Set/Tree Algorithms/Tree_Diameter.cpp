#include <bits/stdc++.h>

using namespace std;

const int M = 2e5+2;
int n, far = 1, mx, vis[M], dis[M];
vector<int> adj[M];

void bfs(int n) {
    queue<int> q;
    memset(dis, 0, sizeof(dis));
    memset(vis, 0, sizeof(vis));

    mx = 0;
    q.push(n);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        vis[u] = true;

        for (int v : adj[u]) {
            if (!vis[v]) {
                q.push(v);

                if (dis[far] == mx)
                    far = v;

                mx = max(mx, dis[v]);
                dis[v] = dis[u] + 1;
                vis[v] = true;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;

    for (int i = 0, a, b; i < n - 1; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bfs(1);
    bfs(far);

    cout << mx << '\n';
}
