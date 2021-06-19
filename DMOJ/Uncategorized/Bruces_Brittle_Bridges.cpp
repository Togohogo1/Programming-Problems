#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

typedef long long ll;

const int M = 2e5+2;
ll N, tmp, ans, v1[M], v2[M], v3[M], tr[M], gr[M], id[M];
vector<pair<ll, ll>> adj[M];

void grp(ll u) {
    v1[u] = true;

    for (auto v : adj[u]) {
        if (!v1[v.f] && v.s >= 2) {
            tmp += tr[v.f];
            grp(v.f);
        }
    }
}

void setgrp(ll u, ll val) {
    v2[u] = true;

    for (auto v : adj[u]) {
        if (!v2[v.f] && v.s >= 2) {
            gr[v.f] = tmp;
            id[v.f] = val;
            setgrp(v.f, val);
        }
    }
}

void mx(ll u) {
    v3[u] = true;

    for (auto v : adj[u]) {
        if (!v3[v.f]) {
            if (id[v.f] != id[u])
                gr[v.f] += gr[u];
            else
                gr[v.f] = gr[u];

            mx(v.f);
        }
    }

    if (adj[u].size() == 1)
        ans = max(ans, gr[u]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    for (ll i = 1; i <= N; i++) {
        cin >> tr[i];
    }

    for (ll i = 0, A, B, t; i < N - 1; i++) {
        cin >> A >> B >> t;
        adj[A].push_back({B, t});
        adj[B].push_back({A, t});
    }

    for (ll i = 1; i <= N; i++) {
        tmp = tr[i];

        if (!v1[i]) {
            grp(i);
            gr[i] = tmp;
            id[i] = i;
        }

        if (!v2[i])
            setgrp(i, i);
    }

    mx(1);
    cout << ans << '\n';
}
