#include<bits/stdc++.h>

using namespace std;

const int MM = 102;
int N, M, W, ant[MM], dis[MM], vis[MM];
queue<int> q;
vector<int> adj[MM];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M;

    for (int i = 1, X, Y; i <= M; i++) {
        cin >> X >> Y;
        adj[X].push_back(Y);
        adj[Y].push_back(X);
    }

    cin >> W;

    for (int i = 1, x; i <= W; i++) {
        cin >> x;
        q.push(x);
        vis[x] = true;
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int nxt : adj[cur]) {
            if (!vis[nxt]) {
                q.push(nxt);
                vis[nxt] = true;
                ant[nxt] = ant[cur] + 4;
            }
        }
    }

    memset(vis, 0, sizeof(vis));
    q.push(1);
    vis[1] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int nxt : adj[cur]) {
            if (!vis[nxt] && dis[cur] + 1 < ant[nxt]) {
                q.push(nxt);
                vis[nxt] = true;
                dis[nxt] = dis[cur] + 1;
            }
        }
    }

    if (vis[N])
        cout << dis[N] << '\n';
    else
        cout << "sacrifice bobhob314\n";
}
