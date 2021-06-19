#include<bits/stdc++.h>

using namespace std;

const int M = 2e5+2;
int n, cnt[M];
vector<int> adj[M];

void dfs(int u, int pre) {
    cnt[u] = 1;

    for (int v : adj[u]) {
        dfs(v, u);
        cnt[u] += cnt[v];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;

    for (int i = 2, e; i <= n; i++) {
        cin >> e;
        adj[e].push_back(i);
    }

    dfs(1, -1);

    for (int i = 1; i <= n; i++) {
        cout << cnt[i] - 1 << ' ';
    }

    cout << '\n';
}
