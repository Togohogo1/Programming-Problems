#include <bits/stdc++.h>

using namespace std;

int N, d, e, f;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    for (int i = 1, a, b, c, td, te, tf; i <= N; i++) {
        cin >> a >> b >> c;

        td = max(e, f) + a;
        te = max(d, f) + b;
        tf = max(d, e) + c;

        d = td;
        e = te;
        f = tf;
    }

    cout << max({d, e, f}) << '\n';
}
