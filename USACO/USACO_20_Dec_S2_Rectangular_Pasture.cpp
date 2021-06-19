#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

typedef long long ll;
typedef pair<int, int> pii;

const int M = 2502;
ll N, ans, grid[M][M];
vector<pii> pts;

int cmp(pii a, pii b) {
    return a.s < b.s;
}

ll query(int r1, int c1, int r2, int c2) {
    return grid[r2][c2] - grid[r2][c1-1] - grid[r1-1][c2] + grid[r1-1][c1-1] + 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    for (int i = 0, x, y; i < N; i++) {
        cin >> x >> y;
        pts.push_back({x, y});
    }

    sort(pts.begin(), pts.end());

    for (int i = 0; i < N; i++) {
        pts[i].f = i + 1;
    }

    sort(pts.begin(), pts.end(), cmp);

    for (int i = 0; i < N; i++) {
        pts[i].s = i + 1;
    }

    for (int i = 0; i < N; i++) {
        grid[pts[i].f][pts[i].s] = 1;
    }

    // 2D Prefix sum array
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            grid[i][j] += grid[i][j-1] + grid[i-1][j] - grid[i-1][j-1];
        }
    }

    // For each pair of cows, subsets = (left+1) * (right+1)
    // Bounded by height of rectangle formed by the 2 cows
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int r1 = pts[i].f, c1 = pts[i].s, r2 = pts[j].f, c2 = pts[j].s;
            int mir = min(r1, r2), mic = min(c1, c2), mar = max(r1, r2), mac = max(c1, c2);
            ans += query(mir, 0, mar, mic-1) * query(mir, mac+1, mar, N);
        }
    }

    cout << ans + 1 + N << '\n';
}
