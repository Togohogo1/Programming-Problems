#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Edge {
    int wt, st, ed;
};

const int M = 2e5+2;
ll n, m, cnt, join, par[M], rnk[M];
vector<Edge> edges;

bool cmp (Edge e1, Edge e2) {
    return e1.wt < e2.wt;
}

ll find(int v) {
    if (v == par[v])
        return v;

    return par[v] = find(par[v]);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);

    if (a != b) {
        if (rnk[a] > rnk[b])
            swap(a, b);

        par[b] = a;
        rnk[a] += rnk[b];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        par[i] = i;
        rnk[i] = 1;
    }

    for (int i = 0, a, b, c; i < m; i++) {
        cin >> a >> b >> c;
        edges.push_back({c, a, b});
    }

    sort(edges.begin(), edges.end(), cmp);

    for (auto i : edges) {
        if (find(i.st) != find(i.ed)) {
            join++;
            unite(i.st, i.ed);
            cnt += i.wt;
        }
    }

    if (n - join == 1)
        cout << cnt << '\n';
    else
        cout << "IMPOSSIBLE" << '\n';
}
