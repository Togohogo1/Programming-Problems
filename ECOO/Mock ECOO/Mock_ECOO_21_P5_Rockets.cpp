#include <bits/stdc++.h>

using namespace std;

const int MM = 1e5+2;
int N, A, B, C, D, dp[MM], vis[MM];
string win = "NOU >:(\n";
vector<int> adj[MM];

void dfs(int u) {
    vis[u] = true;

    for (int v : adj[u]) {
        if (!vis[v]) {
            dfs(v);
            dp[u] += 1 + dp[v];
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    for (int i = 0; i < N - 1; i++) {
        cin >> A >> B;
        adj[A].push_back(B);
        adj[B].push_back(A);
    }

    cin >> C >> D;
    dfs(C);

    if ((dp[C]-dp[D]-1) & 1 || dp[D] & 1)
        win = "Let's play >:)\n";

    cout << win;
}
