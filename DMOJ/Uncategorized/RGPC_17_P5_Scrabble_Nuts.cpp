#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MM = 1e4+2;
ll N, M, ans, dpc[MM], dpp[MM];
char x[MM], y[MM];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> x[i];
    }

    for (int i = 1; i <= M; i++) {
        cin >> y[i];
        dpp[i] = dpp[i-1] + 1;
    }

    for (int i = 1; i <= N; i++) {
        dpc[0] = i;

        for (int j = 1; j <= M; j++) {
            dpc[j] = min(dpp[j-1]+(x[i]!=y[j]), min(dpc[j-1]+1, dpp[j]+1));
        }

        for (int j = 0; j <= M; j++) {
            dpp[j] = dpc[j];
        }
    }

    for (int i = 1; i < M; i++) {
        ans += dpc[i];
    }

    cout << ans << '\n';
}
