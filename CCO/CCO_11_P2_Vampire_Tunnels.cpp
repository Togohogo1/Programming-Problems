#include <bits/stdc++.h>

using namespace std;

typedef tuple<int, int, int> ti3;

const int MM = 1602, INF = 0x3f3f3f3f;
int S, N, E, ans = INF, dis[MM][3602];
vector<ti3> adj[MM];

void dijk(int u) {
    priority_queue<ti3> pq;
    memset(dis, INF, sizeof(dis));

    dis[u][0] = 0;
    pq.push({0, u, 0});

    while (!pq.empty()) {
        int cv = get<1>(pq.top()), cw = -get<0>(pq.top()), ch = get<2>(pq.top());
        pq.pop();

        if (cv == N - 1)
            break;

        if (dis[cv][ch] < cw)
            continue;

        for (auto nx : adj[cv]) {
            int nv = get<0>(nx), nw = get<1>(nx), nh = get<2>(nx);

            if (ch + nh > S)
                continue;

            if (cw + nw < dis[nv][ch+nh]) {
                dis[nv][ch+nh] = cw + nw;
                pq.push({-dis[nv][ch+nh], nv, ch+nh});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> S >> N >> E;

    for (int i = 0, s, t, d, u; i < E; i++) {
        cin >> s >> t >> d >> u;
        adj[s].push_back({t, d, u*d});
        adj[t].push_back({s, d, u*d});
    }

    dijk(0);

    for (int i = 0; i <= S; i++) {
        ans = min(ans, dis[N-1][i]);
    }

    cout << (ans == INF ? -1 : ans) << '\n';
}
