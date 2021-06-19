#include <bits/stdc++.h>

using namespace std;

const int M = 2e5+2;
int N, R, X, Y, ans = M, dist[M], vis[M], pre[M];
vector<int> adj[M], path;
queue<int> q;

void bfs() {
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int nxt : adj[cur]) {
            if (!vis[nxt]) {
                q.push(nxt);
                vis[nxt] = true;
                dist[nxt] = dist[cur] + 1;
            }
        }
    }
}

void dfs(int u) {
    vis[u] = true;

    for (int v : adj[u]) {
        if (!vis[v]) {
            pre[v] = u;
            dfs(v);
        }
    }
}

void find(int st, int ed) {
    int tmp = st;
    path.push_back(tmp);

    while (tmp != ed) {
        int ntmp = pre[tmp];
        path.push_back(ntmp);
        tmp = ntmp;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> R;

    for (int i = 1, a, b; i < N; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 0, r; i < R; i++) {
        cin >> r;
        q.push(r);
        vis[r] = true;
    }

    bfs();
    memset(vis, 0, sizeof(vis));

    cin >> X >> Y;

    dfs(Y);
    find(X, Y);

    for (int i : path) {
        ans = min(ans, dist[i]);
    }

    cout << ans;
}
