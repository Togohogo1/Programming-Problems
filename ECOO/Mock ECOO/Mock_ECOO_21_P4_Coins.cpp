#include <bits/stdc++.h>

using namespace std;

int N, X, ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> X;

    for (int i = 0, A, V; i < N; i++) {
        cin >> A >> V;

        if (A < X)
            ans = max(ans, A*V);
        else
            ans = max(ans, X*V);
    }

    cout << ans << '\n';
}
