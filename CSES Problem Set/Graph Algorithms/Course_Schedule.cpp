#include <bits/stdc++.h>

using namespace std;

const int M = 1e5+2;
int n, m, cnt, indeg[M];
vector<int> adj[M], ord;

bool topsort() {
    queue<int> q;

    for (int i = 1; i <= n; i++) {
        if (!indeg[i])
            q.push(i);
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        ord.push_back(u);
        cnt++;

        for (int v : adj[u]) {
            if (!--indeg[v])
                q.push(v);
        }
    }

    return cnt == n;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;

    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        indeg[b]++;
    }

    if (topsort()) {
        for (int i : ord) {
            cout << i << ' ';
        }
    } else
        cout << "IMPOSSIBLE";

    cout << '\n';
}
