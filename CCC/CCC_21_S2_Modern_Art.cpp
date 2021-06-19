#include <bits/stdc++.h>

using namespace std;

const int MM = 5e6+2;
int M, N, K, ans, r[MM], c[MM];
char op;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> M >> N >> K;

    for (int i = 0, x; i < K; i++) {
        cin >> op >> x;

        if (op == 'R')
            r[x] ^= 1;
        else if (op == 'C')
            c[x] ^= 1;
    }

    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            ans += r[i]^c[j];
        }
    }

    cout << ans << '\n';
}
