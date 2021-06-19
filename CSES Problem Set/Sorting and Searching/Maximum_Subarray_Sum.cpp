#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, ans, best;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;

    for (ll i = 0, x; i < n; i++) {
        cin >> x;
        best = (i == 0 ? x : max(x, best+x));
        ans = (i == 0 ? x : max(ans, best));
    }

    cout << ans << '\n';
}
