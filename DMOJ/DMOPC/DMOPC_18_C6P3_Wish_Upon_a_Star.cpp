#include<bits/stdc++.h>

using namespace std;

const int MM = 2e5+2;
int N, M, cnt, vert, ans, vis[MM];
vector<int> adj[MM];
set<int> verts;

void dfs(int u) {
    vis[u] = 1;
    vert++;

    for(int v : adj[u]) {
        cnt++;

        if (!vis[v]) {
            dfs(v);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M;

    for (int i = 0, a, b; i < M; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= N; i++) {
        if (!vis[i]) {
            dfs(i);
            ans += abs(vert - cnt/2 - 1);
            vert = 0;
            cnt = 0;
        }
    }

    cout << (ans <= 1 ? "YES\n" : "NO\n");
}
