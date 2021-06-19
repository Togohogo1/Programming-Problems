#include <bits/stdc++.h>

using namespace std;

const int M = 1e4+2;
int N, deep, def, ans;
vector<int> adj[M];

void bfs(int u) {
    ans = -1;
    queue<int> q;
    vector<int> vis(M, 0), dist(M, 0);

    q.push(u);
    vis[u] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int nxt : adj[cur]) {
            if (!vis[nxt]) {
                q.push(nxt);
                vis[nxt] = true;

                dist[nxt] = dist[cur] + 1;
                ans = max(ans, dist[nxt]);
                deep = nxt;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    for (int i = 1, x, y; i < N; i++) {
        cin >> x >> y;
        def = x;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    bfs(def);
    bfs(deep);

    cout << ans << '\n';
}
