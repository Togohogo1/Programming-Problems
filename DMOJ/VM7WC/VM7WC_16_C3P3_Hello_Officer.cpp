#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

typedef pair<int, int> pii;

const int MM = 2002, INF = 1e9;
int N, M, B, Q, dis[MM], vis[MM];
vector<pii> adj[MM];

void dijk(int u) {
    priority_queue<pii> pq;

    for (int i = 1; i <= N; i++) {
        dis[i] = INF;
    }

    dis[u] = 0;
    pq.push({0, u});

    while (!pq.empty()) {
        int cur = pq.top().s;
        pq.pop();

        if (!vis[cur]) {
            vis[cur] = true;

            for (auto nxt : adj[cur]) {
                int v = nxt.f, w = nxt.s;

                if (dis[cur] + w < dis[v]) {
                    dis[v] = dis[cur] + w;
                    pq.push({-dis[v], v});
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M >> B >> Q;

    for (int i = 0, X, Y, Z; i < M; i++) {
        cin >> X >> Y >> Z;
        adj[X].push_back({Y, Z});
        adj[Y].push_back({X, Z});
    }

    dijk(B);

    for (int i = 0, A; i < Q; i++) {
        cin >> A;
        cout << (dis[A] == INF ? -1 : dis[A]) << '\n';
    }
}
