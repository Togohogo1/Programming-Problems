#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

typedef long long ll;
typedef pair<ll, ll> pll;

const ll MM = 2e5+2, INF = 1e18;
ll N, M, dis[MM];
vector<pll> adj[MM];

void dijk(int u) {
    priority_queue<pll> pq;

    dis[u] = INF;
    pq.push({0, u});

    while (!pq.empty()) {
        ll cv = pq.top().s, cw = pq.top().f;
        pq.pop();

        if (dis[cv] < cw)
            continue;

        for (auto nx : adj[cv]) {
            ll nv = nx.f, nw = nx.s;

            if (dis[nv] < min(dis[cv], nw)) {
                dis[nv] = min(dis[cv], nw);
                pq.push({dis[nv], nv});
            }
        }
    }

    dis[1] = 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M;

    for (int i = 0, a, b, p; i < M; i++) {
        cin >> a >> b >> p;
        adj[a].push_back({b, p});
        adj[b].push_back({a, p});
    }

    dijk(1);

    for (int i = 1; i <= N; i++) {
        cout << dis[i] << '\n';
    }
}
