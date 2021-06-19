#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int M = 2002, INF = 1e9+2;
int N, Hx, Hy, Ax, Ay, ans = INF, dpH[M][M], dpA[M][M];
pii H, A, pts[M];

int dist(pii p1, pii p2) {
    return abs(p1.first-p2.first) + abs(p1.second-p2.second);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    fill_n(&dpH[0][0], M*M, INF);
    fill_n(&dpA[0][0], M*M, INF);

    cin >> N >> Hx >> Hy >> Ax >> Ay;

    H = {Hx, Hy};
    A = {Ax, Ay};

    for (int i = 1, x, y; i <= N; i++) {
        cin >> x >> y;
        pts[i] = {x, y};
    }

    dpH[1][0] = dist(H, pts[1]);
    dpA[1][0] = dist(A, pts[1]);

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < i - 1; j++) {
            // Active person continues to pick up paintings
            dpH[i][j] = dpH[i-1][j] + dist(pts[i-1], pts[i]);
            dpA[i][j] = dpA[i-1][j] + dist(pts[i-1], pts[i]);

            // Active and resting swap, active picks up paintings
            dpH[i][i-1] = min(dpH[i][i-1], dpH[i-1][j] + dist(pts[i], (j == 0 ? A : pts[j])));
            dpA[i][i-1] = min(dpA[i][i-1], dpA[i-1][j] + dist(pts[i], (j == 0 ? H : pts[j])));
        }
    }

    for (int i = 0; i < N; i++) {
        ans = min(ans, min(dpH[N][i], dpA[N][i]));
    }

    cout << ans << '\n';
}
