#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

typedef pair<int, int> pii;

const int MM = 2e4+2, INF = 2e9;
int N, M, ans, dis[MM][2];
vector<pii> adj[MM];

int dijk(int u) {
    priority_queue<pii> pq;

    for (int i = 1; i < MM; i++) {
        dis[i][0] = dis[i][1] = INF;
    }

    dis[1][0] = 0;
    pq.push({0, u});

    while (!pq.empty()) {
        int cv = pq.top().s, cw = -pq.top().f;
        pq.pop();

        if (dis[cv][1] < cw)
            continue;

        for (auto nxt : adj[cv]) {
            int nv = nxt.f, nw = nxt.s, nd = cw + nw;

            if (nd < dis[nv][1] && nd != dis[nv][0]) {
                dis[nv][1] = nd;
                sort(dis[nv], dis[nv]+2);
                pq.push({-nd, nv});
            }
        }
    }

    return max(dis[N][0], dis[N][1]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M;

    for (int i = 0, A, B, W; i < M; i++) {
        cin >> A >> B >> W;
        adj[A].push_back({B, W});
    }

    ans = dijk(1);
    cout << (ans == INF ? -1 : ans) << '\n';
}
