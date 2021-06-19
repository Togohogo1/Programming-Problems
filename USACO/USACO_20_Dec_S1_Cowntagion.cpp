#include <bits/stdc++.h>

using namespace std;

const int M = 1e5+2;
int N, ans, vis[M];
vector<int> adj[M];

int dbl(int n) {
    return ceil(log2(n+1));
}

void bfs(int st) {
    queue<int> q;
    q.push(st);

    while (!q.empty()) {
        int u = q.front(), tmp = 0;

        q.pop();
        vis[u] = true;

        for (int v : adj[u]) {
            if (!vis[v]) {
                q.push(v);
                tmp++;
            }
        }

        if (tmp > 0)
            ans += tmp + dbl(tmp);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    for (int i = 0, a, b; i < N - 1; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bfs(1);
    cout << ans << '\n';
}
