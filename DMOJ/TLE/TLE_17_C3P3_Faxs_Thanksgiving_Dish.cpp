#include<bits/stdc++.h>

using namespace std;

const int MM = 3e5+3, MAX = INT_MAX;
int N, M, ans, cnt[MM], vis[MM];
vector<int> adj[MM];

int dfs(int u) {
    vis[u] = true;
    int mi = MAX;

    for (int v : adj[u]) {
        if (!vis[v])
            mi = min(mi, dfs(v));
        else
            mi = 0;
    }

    // Pushing up
    if (mi != MAX)
        return mi + cnt[u];

    // Leaf node
    return cnt[u];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M;

    for (int i = 0, itm, n; i < M; i++) {
        cin >> itm >> n;

        for (int j = 0, igr; j < n; j++) {
            cin >> igr;
            adj[itm].push_back(igr);
        }
    }

    for (int i = 1; i <= N; i++) {
        cin >> cnt[i];
    }

    cout << dfs(1) << '\n';
}
