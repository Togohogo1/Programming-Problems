#include <bits/stdc++.h>

using namespace std;

int M, N, n, bit[3002][3002];

int query(int r, int c) {
    int sum = 0;

    for (int i = r; i > 0; i -= i&-i) {
        for (int j = c; j > 0; j -= j&-j) {
            sum += bit[i][j];
        }
    }

    return sum;
}

int query2d(int r1, int c1, int r2, int c2) {
    return query(r2, c2) - query(r2, c1-1) - query(r1-1, c2) + query(r1-1, c1-1);
}

void update(int r, int c, int val) {
    for (int i = r; i <= M; i += i&-i) {
        for (int j = c; j <= N; j += j&-j) {
            bit[i][j] += val;
        }
    }
}

int change(int r1, int c1) {
    return query(r1, c1) - query(r1-1, c1) - query(r1, c1-1) + query(r1-1, c1-1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> M >> N;

    while (true) {
        int op, R1, C1, R2, C2;
        cin >> op >> R1 >> C1 >> R2;

        int n = (R1+C1) & 1 ? 1 : -1;

        if (op == 1)
            update(R1, C1, n*R2-change(R1, C1));
        else if (op == 2) {
            cin >> C2;
            cout << n*query2d(R1, C1, R2, C2) << '\n';
        } else
            break;
    }
}
