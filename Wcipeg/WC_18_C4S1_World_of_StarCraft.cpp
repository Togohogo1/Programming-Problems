#include <bits/stdc++.h>

using namespace std;

const int MM = 1e5+2;
int N, M, K, ans, par[MM], rnk[MM];
char let[MM];

void init() {
    for (int i = 1; i <= N; i++) {
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
        rnk[a] += b;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++) {
        cin >> let[i];
    }

    init();

    for (int i = 1, A, B; i <= M; i++) {
        cin >> A >> B;

        if (let[A] == let[B])
            unite(A, B);
    }

    for (int i = 1, X, Y; i <= K; i++) {
        cin >> X >> Y;
        ans += find(X) == find(Y);
    }

    cout << ans << '\n';
}
