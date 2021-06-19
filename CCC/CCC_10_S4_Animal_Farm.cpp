#include <bits/stdc++.h>

using namespace std;

struct edge {
    int wt, st, ed;
};

bool cmp(edge a, edge b) {
    return a.wt < b.wt;
}

const int MM = 1002;
int M, ans1, ans2, par[MM], rnk[MM], adj[MM][MM], idx[MM][MM];
vector<int> dt[MM];
vector<edge> edges[MM], mst1, mst2;

void init() {
    for (int i = 0; i < MM; i++) {
        par[i] = i;
        rnk[i] = 1;
    }
}

int find(int v) {
    if (v == par[v])
        return v;

    return par[v] = find(par[v]);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);

    if (a != b) {
        if (rnk[a] < rnk[b])
            swap(a, b);

        par[b] = a;
        rnk[a] += rnk[b];
    }
}

int kruskal(vector<edge> &mst) {
    int ans = 0;

    init();
    sort(mst.begin(), mst.end(), cmp);

    for (edge i : mst) {
        if (find(i.st) != find(i.ed)) {
            unite(i.st, i.ed);
            ans += i.wt;
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> M;

    // Reading input
    for (int i = 0, ep; i < M; i++) {
        cin >> ep;
        dt[i].push_back(ep);

        for (int j = 0, x; j < 2*ep; j++) {
            cin >> x;
            dt[i].push_back(x);
        }
    }

    // Processing input
    for (int i = 0; i < M; i++) {
        for (int j = 1; j <= dt[i][0]; j++) {
            int u = dt[i][j], v = dt[i][j%dt[i][0]+1], w = dt[i][j+dt[i][0]];

            if (u < v)
                swap(u, v);

            adj[u][v]++;
            edges[i+1].push_back({w, u, v});

            if (adj[u][v] == 2) {
                mst1.push_back({w, i+1, idx[u][v]});  // mst1: MST of pens without outer area
                mst2.push_back({w, i+1, idx[u][v]});  // mst2: MST of pens with outer area
            }

            // adj[u][v] appearing twice at max, index mapping works
            idx[u][v] = i+1;
        }
    }

    // Edge connecting outer area to areas adjacent to outer area
    for (int i = 1; i <= M; i++) {
        for (edge j : edges[i]) {
            if (adj[j.st][j.ed] == 1)
                mst2.push_back({j.wt, i, 0});
        }
    }

    ans1 = kruskal(mst1);
    ans2 = kruskal(mst2);

    if (M == 1)
        cout << 0;
    else if (ans1 == 0)
        cout << ans2 << '\n';
    else
        cout << min(ans1, ans2) << '\n';
}
