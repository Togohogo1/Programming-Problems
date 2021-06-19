#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

typedef pair<int, int> pii;

const int M = 5002, INF = 2e9;
int N, T, K, D, ans = INF, dis[M], nDis[M], vis[M];
vector<pii> adj[M];

void dijk(int u) {
    priority_queue<pii> pq;

    for (int i = 1; i < M; i++) {
        dis[i] = INF;
    }

    dis[1] = 0;
    pq.push({0, u});

    while (!pq.empty()) {
        int cv = pq.top().s, cw = -pq.top().f;
        pq.pop();

        if (dis[cv] < cw)
            continue;

        for (auto nx : adj[cv]) {
            int nv = nx.f, nw = nx.s, nd = cw + nw;

            if (nd < dis[nv]) {
                dis[nv] = nd;
                pq.push({-nd, nv});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> T;

    for (int i = 0, x, y, C; i < T; i++) {
        cin >> x >> y >> C;
        adj[x].push_back({y, C});
        adj[y].push_back({x, C});
    }

    cin >> K;

    for (int i = 0, z, P; i < K; i++) {
        cin >> z >> P;
        nDis[z] += P;
        vis[z] = true;
    }

    cin >> D;
    dijk(D);

    for (int i = 1; i <= N; i++) {
        if (vis[i])
            ans = min(ans, dis[i]+nDis[i]);
    }

    cout << ans << '\n';
}
