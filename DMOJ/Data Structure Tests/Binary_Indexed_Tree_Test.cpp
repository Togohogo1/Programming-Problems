#include <bits/stdc++.h>

using namespace std;

int N, M;
long long tree[100002], freq[100002];

long long get(int idx, long long bit[]) {
    int sum = bit[idx];

    if (idx > 0) {
        int z = idx - (idx & -idx);
        int y = idx - 1;

        while (y > z) {
            sum -= bit[y];
            y -= (y & -y);
        }
    }

    return sum;
}

long long query(int idx, long long bit[]) {
    long long sum = 0;

    while (idx > 0) {
        sum += bit[idx];
        idx -= (idx & -idx);
    }

    return sum;
}

void update(int idx, int val, long long bit[]) {
    while (idx <= 100002) {
        bit[idx] += val;
        idx += (idx & -idx);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        int n;
        cin >> n;

        update(n, 1, freq);
        update(i, n, tree);
    }

    while (M--) {
        char q;
        int a, b, l, r, v;

        cin >> q;

        if (q == 'C') {
            cin >> a >> b;
            int getA = get(a, tree);

            update(getA, -1, freq);
            update(b, 1, freq);
            update(a, b-getA, tree);

        } else if (q == 'S') {
            cin >> l >> r;
            cout << query(r, tree) - query(l-1, tree) << '\n';

        } else {
            cin >> v;
            cout << query(v, freq) << '\n';
        }
    }
}
