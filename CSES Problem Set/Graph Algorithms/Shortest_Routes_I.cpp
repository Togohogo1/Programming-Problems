#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

typedef long long ll;
typedef pair<ll, ll> pll;

const ll M = 2e5+2, INF = 1e18;
ll n, m, dis[M], vis[M];
vector<pll> adj[M];

void dijk(int u) {
    priority_queue<pll> pq;

    for (int i = 1; i < M; i++) {
        dis[i] = INF;
    }

    dis[u] = 0;
    pq.push({0, u});

    while (!pq.empty()) {
        ll cv = pq.top().s, cw = -pq.top().f;
        pq.pop();

        if (dis[cv] < cw)
            continue;

        for (auto nxt : adj[cv]) {
            ll nv = nxt.f, nw = nxt.s, nd = cw + nw;

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

    cin >> n >> m;

    for (int i = 0, a, b, c; i < m; i++) {
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    dijk(1);

    for (int i = 1; i <= n; i++) {
        cout << dis[i] << ' ';
    }

    cout << '\n';
}
