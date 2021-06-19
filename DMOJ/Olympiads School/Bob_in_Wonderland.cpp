#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MM = 1e6+2;
ll N, M, mx, psa[MM];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M;

    for (ll i = 1, h; i <= N; i++) {
        cin >> h;
        mx = max(mx, h);
        psa[h]++;
    }

    for (int i = 1; i <= mx; i++) {
        psa[i] += psa[i-1];
    }

    for (int i = 0, t; i < M; i++) {
        cin >> t;
        cout << (t > mx ? 0 : psa[mx] - psa[t-1]) << '\n';
    }
}
