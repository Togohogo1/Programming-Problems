#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

const ll M = 2e5+2, INF = 1e18;
ll n, m, ans = INF, disF[M], disB[M], vis[M];
vpll adj1[M], adj2[M];
vector<pair<pll, int>> eds;

void dijk(int u, ll dis[M], vpll adj[M]) {
    priority_queue<pll> pq;

    for (int i = 1; i < M; i++) {
        dis[i] = INF;
        vis[i] = 0;
    }

    dis[u] = 0;
    pq.push({0, u});

    while (!pq.empty()) {
        ll cur = pq.top().s;
        pq.pop();

        if (!vis[cur]) {
            vis[cur] = true;

            for (auto nxt : adj[cur]) {
                ll v = nxt.f, w = nxt.s;

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

    cin >> n >> m;

    for (ll i = 0, a, b, c; i < m; i++) {
        cin >> a >> b >> c;
        adj1[a].push_back({b, c});
        adj2[b].push_back({a, c});
        eds.push_back({{a, b}, c});
    }

    dijk(1, disF, adj1);
    dijk(n, disB, adj2);

    for (auto i : eds) {
        ans = min(ans, disF[i.f.f] + i.s/2 + disB[i.f.s]);
    }

    cout << ans << '\n';
}
