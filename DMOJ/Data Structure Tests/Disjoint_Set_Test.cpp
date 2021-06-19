#include<bits/stdc++.h>

using namespace std;

#define f first
#define s second

const int MM = 1e5+2;
int N, M, par[MM], rnk[MM];
vector<int> ans;
vector<pair<int, pair<int, int>>> edges;

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

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        par[i] = i;
        rnk[i] = 1;
    }

    for (int i = 1, u, v; i <= M; i++) {
        cin >> u >> v;
        edges.push_back({i, {u, v}});
    }

    for (auto i : edges) {
        if (find_set(i.s.f) != find_set(i.s.s)) {
            ans.push_back(i.f);
            union_sets(i.s.f, i.s.s);
        }
    }

    if (ans.size() == N - 1) {
        for (int i : ans) {
            cout << i << '\n';
        }
    } else
        cout << "Disconnected Graph\n";
}
