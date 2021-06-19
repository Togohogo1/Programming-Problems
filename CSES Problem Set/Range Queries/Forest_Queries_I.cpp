#include<bits/stdc++.h>

using namespace std;

const int M = 1002;
int n, q, psa[M][M];
char tree;

void init() {
    for (int i = 1; i < M; i++) {
        for (int j = 1; j < M; j++) {
            psa[i][j] += psa[i][j-1] + psa[i-1][j] - psa[i-1][j-1];
        }
    }
}

int query2d(int y1, int x1, int y2, int x2) {
    return psa[y2][x2] + psa[y1-1][x1-1] - psa[y2][x1-1] - psa[y1-1][x2];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> tree;

            if (tree == '*')
                psa[i][j] = 1;
        }
    }

    init();

    for (int i = 0, y1, x1, y2, x2; i < q; i++) {
        cin >> y1 >> x1 >> y2 >> x2;
        cout << query2d(y1, x1, y2, x2) << '\n';
    }
}
