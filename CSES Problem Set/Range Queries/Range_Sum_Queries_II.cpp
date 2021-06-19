#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int M = 2e5+2;
int n, q;
ll bit[M];

ll query(int idx) {
    ll ans = 0;

    for (int i = idx; i > 0; i -= i&-i) {
        ans += bit[i];
    }

    return ans;
}

void update(int idx, int v) {
    for (int i = idx; i < M; i += i&-i) {
        bit[i] += v;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> q;

    for (int i = 1, xi; i <= n; i++) {
        cin >> xi;
        update(i, xi);
    }

    for (int i = 0, op, a, b; i < q; i++) {
        cin >> op >> a >> b;

        if (op == 1)
            update(a, b-(query(a)-query(a-1)));
        else
            cout << query(b) - query(a-1) << '\n';
    }
}
