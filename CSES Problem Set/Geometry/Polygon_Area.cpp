#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, pts[1002][2];

ll shoelace() {
    ll ans = 0;

    for (int i = 0; i < n - 1; i++) {
        ans += pts[i][0]*pts[i+1][1];
        ans -= pts[i][1]*pts[i+1][0];
    }

    ans += pts[n-1][0]*pts[0][1];
    ans -= pts[0][0]*pts[n-1][1];

    return abs(ans);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;

    for (int i = 0, x, y; i < n; i++) {
        cin >> x >> y;
        pts[i][0] = x;
        pts[i][1] = y;
    }

    cout << shoelace() << '\n';
}
