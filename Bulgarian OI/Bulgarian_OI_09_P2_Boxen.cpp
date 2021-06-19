#include<bits/stdc++.h>

using namespace std;

const int M = 1e5+2;
int N, ans, key, vis[M];
vector<int> adj[M];

void dfs(int u) {
    vis[u] = 1;

    for (int v : adj[u]) {
        if (!vis[v]) {
            dfs(v);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    for (int i = 0; i < 2; i++) {
        cin >> N;

        for (int i = 1, key; i <= N; i++) {
            cin >> key;
            adj[key].push_back(i);
            adj[i].push_back(key);
        }

        for (int i = 1; i <= N; i++) {
            if (!vis[i]) {
                ans++;
                dfs(i);
            }
        }

        cout << ans << ' ';

        ans = 0;
        memset(vis, 0, sizeof(vis));

        for (auto &i : adj) {
            i.clear();
        }

    }

    cout << "\n";
}
