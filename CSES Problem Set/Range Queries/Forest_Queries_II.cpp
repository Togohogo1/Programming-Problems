#include <bits/stdc++.h>

using namespace std;

const int M = 1005;
int n, q, bit[M][M];
char tree;

int query(int r, int c) {
    int ans = 0;

    for (int i = r + 1; i > 0; i -= i&-i) {
        for (int j = c + 1; j > 0; j -= j&-j) {
            ans += bit[i][j];
        }
    }

    return ans;
}

int query2D(int r1, int c1, int r2, int c2) {
    return query(r2, c2) - query(r1-1, c2) - query(r2, c1-1) + query(r1-1, c1-1);
}

void update(int r, int c, int val) {
    for (int i = r + 1; i <= M; i += i&-i) {
        for (int j = c + 1; j <= M; j += j&-j) {
            bit[i][j] += val;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> tree;
            update(i, j, (tree=='*'));
        }
    }

    for (int i = 0, op, y1, x1, y2, x2, tmp; i < q; i++) {
        cin >> op;

        if (op == 1) {
            cin >> y1 >> x1;
            tmp = query2D(y1, x1, y1, x1);
            update(y1, x1, (!tmp ? 1 : -1));
        } else {
            cin >> y1 >> x1 >> y2 >> x2;
            cout << query2D(y1, x1, y2, x2) << '\n';
        }
    }
}
