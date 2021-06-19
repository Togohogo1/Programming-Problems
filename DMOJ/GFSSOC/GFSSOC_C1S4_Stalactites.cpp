#include <bits/stdc++.h>

using namespace std;

int N, Q, a, b, c, d, e, f;
long long ans, cave[252][252][252];
char op;

long long query(int r, int c, int u) {
    long long sum = 0;

    for (int i = r+1; i > 0; i -= i&-i) {
        for (int j = c+1; j > 0; j -= j&-j) {
            for (int k = u+1; k > 0; k -= k&-k) {
                sum += cave[i][j][k];
            }
        }
    }

    return sum;
}

void update(int r, int c, int u, long long val) {
    for (int i = r+1; i <= 251; i += i&-i) {
        for (int j = c+1; j <= 251; j += j&-j) {
            for (int k = u+1; k <= 251; k += k&-k) {
                cave[i][j][k] += val;
            }
        }
    }
}

long long query3d(int x, int y, int z, int X, int Y, int Z) {
    return query(X, Y, Z)
         - query(x, Y, Z) - query(X, y, Z) - query(X, Y, z)
         + query(X, y, z) + query(x, Y, z) + query(x, y, Z)
         - query(x, y, z);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> Q;

    while (Q--) {
        cin >> op;

        if (op == 'C') {
            cin >> a >> b >> c >> d;
            update(a, b, c, d-query3d(a-1, b-1, c-1, a, b, c));
        } else {
            cin >> a >> b >> c >> d >> e >> f;
            ans += query3d(a-1, b-1, c-1, d, e, f);
        }
    }

    cout << ans << '\n';
}
