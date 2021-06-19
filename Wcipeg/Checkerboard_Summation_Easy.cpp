#include <bits/stdc++.h>

using namespace std;

const int MAX = 3002;
int M, N, n, bit[MAX][MAX];

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
    for (int i = r; i <= MAX; i += i&-i) {
        for (int j = c; j <= MAX; j += j&-j) {
            bit[i][j] += val;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> M >> N;

    while (true) {
        int R, C, X;
        cin >> R >> C >> X;

        if (R == 0 && C == 0 && X == 0)
            break;

        n = (R+C) & 1 ? 1 : -1;
        update(R, C, n*X);
    }

    while (true) {
        int R1, C1, R2, C2;
        cin >> R1 >> C1 >> R2 >> C2;

        if (R1 == 0 && C1 == 0 && R2 == 0 && C2 == 0)
            break;

        n = (R1+C1) & 1 ? 1 : -1;
        cout << n*query2d(R1, C1, R2, C2) << '\n';

    }
}
