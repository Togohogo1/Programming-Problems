#include <bits/stdc++.h>

using namespace std;

int N, T, ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> T;

    for (int i = 0, c, v; i < N; i++) {
        cin >> c >> v;

        if (c <= T)
            ans = max(ans, v);
    }

    cout << ans << '\n';
}
