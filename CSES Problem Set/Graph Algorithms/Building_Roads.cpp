#include <bits/stdc++.h>

using namespace std;

const int M = 2e5+2;
int n, m, cnt, par[M], rnk[M];
vector<pair<int, int>> roads;

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

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        par[i] = i;
        rnk[i] = 1;
    }

    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        unite(a, b);
    }

    for (int i = 1; i <= n; i++) {
        if (find(1) != find(i)) {
            unite(1, i);
            cnt++;
            roads.push_back({1, i});
        }
    }

    cout << cnt << '\n';

    for (auto i : roads) {
        cout << i.first << ' ' << i.second << '\n';
    }
}
