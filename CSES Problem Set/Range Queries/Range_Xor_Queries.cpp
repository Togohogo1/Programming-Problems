#include<bits/stdc++.h>

using namespace std;

const int M = 2e5+2;
int n, q, bit[M];

int query(int idx) {
    int ans = 0;

    for (int i = idx; i > 0; i -= i&-i) {
        ans ^= bit[i];
    }

    return ans;
}

void update(int idx, int val) {
    for (int i = idx; i < M; i += i&-i) {
        bit[i] ^= val;
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

    for (int i = 0, a, b; i < q; i++) {
        cin >> a >> b;
        cout << (query(b) ^ query(a-1)) << '\n';
    }
}
