#include <bits/stdc++.h>

using namespace std;

const int M = 2e5+2;
int N, K, idx, cow[M], vis[M], sz[M];
set<int> to[M];
vector<int> adj[M], cyc[M];

void dfs(int u) {
    cyc[idx].push_back(u);
    vis[u] = true;

    for (int v : adj[u]) {
        if (!vis[v])
            dfs(v);
    }
}

void merge(int a, int b) {
    for (int i : to[b]) {
        to[a].insert(i);
    }

    sz[a] = to[a].size();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        cow[i] = i;
        to[i].insert(i);
    }

    // Simulating one cycle
    for (int i = 0, a, b; i < K; i++) {
        cin >> a >> b;
        to[cow[a]].insert(b);
        to[cow[b]].insert(a);
        swap(cow[a], cow[b]);
    }

    // Graph based on every K cycles
    for (int i = 1; i <= N; i++) {
        adj[cow[i]].push_back(i);
    }

    // Finding disjoint cycles
    for (int i = 1; i <= N; i++) {
        sz[i] = to[i].size();

        if (!vis[i]) {
            idx++;
            dfs(i);
        }
    }

    // Union the sets
    for (int i = 1; i <= idx; i++) {
        for (int j = 1; j < cyc[i].size(); j++) {
            merge(cyc[i][0], cyc[i][j]);
        }

        // Same distance for all cows in a disjoint cycle
        for (int j = 1; j < cyc[i].size(); j++) {
            sz[cyc[i][j]] = sz[cyc[i][0]];
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << sz[i] << '\n';
    }
}
