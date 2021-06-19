#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int wt, od, st, ed, og;
};

bool cmp(Edge e1, Edge e2) {
    return (e1.wt == e2.wt ? e1.od < e2.od : (e1.wt < e2.wt ? 1 : 0));
}

const int MM = 2e5+2;
int N, M, D, ans, mx, par[MM], rnk[MM];
vector<Edge> edges;

void reset() {
    for (int i = 1; i <= M; i++) {
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
        if (rnk[a] > rnk[b])
            swap(a, b);

        par[b] = a;
        rnk[a] += rnk[b];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M >> D;

    reset();

    for (int i = 1, A, B, C; i <= M; i++) {
        cin >> A >> B >> C;
        edges.push_back({C, i, A, B, i<N});  // i<N, part of original plan
    }

    // Sort input based on weight, then input order
    sort(edges.begin(), edges.end(), cmp);

    // Running Kruskal's once to determine max edge of MST and days to complete task assuming D = 0
    for (auto i : edges) {
        if (find(i.st) != find(i.ed)) {
            unite(i.st, i.ed);
            ans += !i.og;
            mx = i.wt;
        }
    }

    reset();

    // Optimal plan either ans or ans - 1 days
    // if D <= mx, D can be subtracted from edge in MST, more optimal than subtracting an edge not in MST
    if (mx < D)
        // Rerunning Kruskal's, goal is to find a way to obtain ans - 1 days
        for (auto i : edges) {
            if (find(i.st) != find(i.ed)) {
                // More optinal for D to be subtracted from an edge smaller than mx or equal to mx and part of original plan
                if (i.wt < mx || (i.wt == mx && i.og))
                    unite(i.st, i.ed);
                // Found edge (guaranteed > mx) in original plan where its more optimal to reduce it than edges in previous case
                else if (i.wt <= D && i.og) {
                    cout << ans - 1 << '\n';
                    return 0;
                }
            }
        }

    cout << ans << '\n';
}
