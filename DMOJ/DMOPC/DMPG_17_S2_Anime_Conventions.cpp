#include<bits/stdc++.h>

using namespace std;

const int M = 1e5+2;
int N, Q, par[M], rnk[M];
char op;

void make_set(int v) {
    par[v] = v;
    rnk[v] = 1;
}

int find_set(int v) {
    if (v == par[v])
        return v;

    return par[v] = find_set(par[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);

    if (a != b) {
        if (rnk[a] < rnk[b])
            swap(a, b);

        par[b] = a;
        rnk[a] += rnk[b];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> Q;

    for (int i = 1; i <= N; i++) {
        make_set(i);
    }

    for (int i = 0, x, y; i < Q; i++) {
        cin >> op >> x >> y;

        if (op == 'A') {
            union_sets(x, y);

        } else {
            cout << (find_set(x) == find_set(y) ? "Y\n" : "N\n");
        }
    }
}
