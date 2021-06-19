#include<bits/stdc++.h>

using namespace std;

const int M = 5e5+2;
int N, last, dis1[M], dis2[M];
vector<int> adj[M];

void bfs(int start, int dis[]) {
    queue<int> q;
    fill(dis, dis+M, -1);

    q.push(start);
    dis[start] = 1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        last = u;

        for (int v : adj[u]) {
            if (dis[v] == -1) {
                q.push(v);
                dis[v] = dis[u] + 1;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    for (int i = 1, u, v; i < N; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 1st BFS to get diameter endpoint
    bfs(1, dis1);

    // 2nd BFS to get dist from endpoint to any other node
    bfs(last, dis1);

    // 3rd BFS to get dist from other endpoint to any other node
    bfs(last, dis2);

    // For every node in the tree, longest dist from it is on tree's diameter's endpoints
    for (int i = 1; i <= N; i++) {
        cout << max(dis1[i], dis2[i]) << '\n';
    }
}
