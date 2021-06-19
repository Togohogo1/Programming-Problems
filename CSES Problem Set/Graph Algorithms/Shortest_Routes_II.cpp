#include <bits/stdc++.h>

using namespace std;

const int MM = 302, INF = 0x3f3f3f3f;
int N, M, T, adj[MM][MM];

void init() {
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            adj[i][j] = (i == j ? 0 : INF);
        }
    }
}

void floyd() {
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                adj[i][j] = (i == j ? 0 : min(adj[i][j], max(adj[i][k], adj[k][j])));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M >> T;
    init();

    for (int i = 0, S, E, H; i < M; i++) {
        cin >> S >> E >> H;
        adj[S][E] = H;
    }

    floyd();

    for (int i = 0, A, B; i < T; i++) {
        cin >> A >> B;
        cout << (adj[A][B] == INF ?  -1 : adj[A][B]) << '\n';
    }
}
