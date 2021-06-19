#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int M = 2e5+2;
ll n, q, arr[M], bit[M];

ll query(int idx) {
    ll ans = 0;

    for (int i = idx; i > 0; i -= i&-i) {
        ans += bit[i];
    }

    return ans + arr[idx];
}

void update(int idx, int val) {
    for (int i = idx; i < M; i += i&-i) {
        bit[i] += val;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    for (int i = 0, op, a, b, c; i < q; i++) {
        cin >> op;

        if (op == 1) {
            cin >> a >> b >> c;
            update(a, c);
            update(b+1, -c);
        } else {
            cin >> a;
            cout << query(a) << '\n';
        }
    }
}
