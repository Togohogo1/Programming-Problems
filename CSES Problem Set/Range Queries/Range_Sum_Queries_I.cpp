#include <bits/stdc++.h>

using namespace std;

const int M = 2e5+2;
long long n, q, psa[M];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> psa[i];
    }

    for (int i = 1; i <= n; i++) {
        psa[i] += psa[i-1];
    }

    for (int i = 0, a, b; i < q; i++) {
        cin >> a >> b;
        cout << psa[b] - psa[a-1] << '\n';
    }
}
