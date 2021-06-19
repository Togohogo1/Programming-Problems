#include <bits/stdc++.h>

using namespace std;

typedef tuple<int, int, int> ti3;

const int MM = 2002, INF = 0x3f3f3f3f;
int K, N, M, A, B, ans = INF, dis[MM][202];
vector<ti3> adj[MM];

void dijk(int u) {
    priority_queue<ti3> pq;
    memset(dis, INF, sizeof(dis));

    dis[u][0] = 0;
    pq.push({0, u, 0});

    while (!pq.empty()) {
        int cv = get<1>(pq.top()), cw = -get<0>(pq.top()), ch = get<2>(pq.top());
        pq.pop();

        if (cv == B)
            break;

        if (dis[cv][ch] < cw)
            continue;

        for (auto nx : adj[cv]) {
            int nv = get<0>(nx), nw = get<1>(nx), nh = get<2>(nx);

            if (nh + ch >= K)
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

    cin >> K >> N >> M;

    for (int i = 0, a, b, t, h; i < M; i++) {
        cin >> a >> b >> t >> h;
        adj[a].push_back({b, t, h});
        adj[b].push_back({a, t, h});
    }

    cin >> A >> B;
    dijk(A);

    for (int i = 0; i < K; i++) {
        ans = min(ans, dis[B][i]);
    }

    cout << (ans == INF ? -1 : ans) << '\n';
}
