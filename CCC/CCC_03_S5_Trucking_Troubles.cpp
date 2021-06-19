#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

typedef pair<int, pair<int, int>> pipii;

const int MM = 1e5+2;
int c, r, d, ans, par[MM], rnk[MM];
vector<pipii> edges;
map<int, int> dests;

int find_set(int v) {
    if (v == par[v])
        return v;

    return par[v] = find_set(par[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);

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

    cin >> c >> r >> d;

    for (int i = 1; i <= c; i++) {
        par[i] = i;
        rnk[i] = 1;
    }

    for (int i = 0, x, y, w; i < r; i++) {
        cin >> x >> y >> w;
        edges.push_back({w, {x, y}});
    }

    for (int i = 0, des; i < d; i++) {
        cin >> des;
        dests[des] = 1;
    }

    sort(edges.begin(), edges.end(), greater<pipii>());

    for (auto i : edges) {
        if (find_set(i.s.f) != find_set(i.s.s)) {
            ans = i.f;
            union_sets(i.s.f, i.s.s);
        }

        if (dests.count(i.s.f))
            dests.erase(i.s.f);

        if (dests.count(i.s.s))
            dests.erase(i.s.s);

        if (dests.empty())
            break;
    }

    cout << ans << '\n';
}
