#include <bits/stdc++.h>

using namespace std;

const int M = 2e5+2;
int n, m, cnt, sz, par[M], rnk[M];

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
        sz = max(sz, rnk[a]);
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

        if (find(a) != find(b)) {
            unite(a, b);
            cnt++;
        }

        cout << n-cnt << ' ' << sz << '\n';
    }
}
