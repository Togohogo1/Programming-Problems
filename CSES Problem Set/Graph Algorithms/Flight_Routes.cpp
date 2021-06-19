#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

typedef long long ll;
typedef pair<ll, ll> pll;

const ll M = 2e5+2, INF = 1e18;
ll n, m, k, ans[M];
vector<pll> adj[M];
priority_queue<ll> kth[M];

void dijk(int u) {
    priority_queue<pll> pq;

    for (int i = 1; i < M; i++) {
        for (int j = 0; j < k; j++) {
            kth[i].push(INF);
        }
    }

    kth[1].pop();
    kth[1].push(0);
    pq.push({0, u});

    while (!pq.empty()) {
        ll cv = pq.top().s, cw = -pq.top().f;
        pq.pop();

        if (kth[cv].top() < cw)
            continue;

        for (auto nxt : adj[cv]) {
            ll nv = nxt.f, nw = nxt.s, nd = cw + nw;

            if (nd < kth[nv].top()) {
                kth[nv].pop();
                kth[nv].push(nd);
                pq.push({-nd, nv});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m >> k;

    for (int i = 0, a, b, c; i < m; i++) {
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    dijk(1);

    for (int i = 0; i < k; i++) {
        ans[i] = kth[n].top();
        kth[n].pop();
    }

    sort(ans, ans+k);

    for (int i = 0; i < k; i++) {
        cout << ans[i] << ' ';
    }

    cout << '\n';
}
