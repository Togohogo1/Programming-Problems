#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

typedef long long ll;
typedef pair<ll, ll> pll;

const ll MM = 1e5+2, INF = 1e18;
ll N, M, ans, disF[MM], disB[MM], vis[MM];
vector<pll> adj[MM];

void dijk(ll u, ll dis[MM]) {
    priority_queue<pll> pq;

    for (int i = 0; i < N; i++) {
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

    cin >> N >> M;

    for (int i = 0, A, B, t; i < M; i++) {
        cin >> A >> B >> t;
        adj[A].push_back({B, t});
        adj[B].push_back({A, t});
    }

    dijk(0, disF);
    dijk(N-1, disB);

    for (int i = 0; i < N; i++) {
        ans = max(ans, disF[i]+disB[i]);
    }

    cout << ans << '\n';
}
