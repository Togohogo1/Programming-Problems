#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int M = 2e5+2, LOG = 18;
ll n, q, arr[M], spt[LOG][M];

void init() {
    for (int i = 1; i < LOG; i++) {
        for (int j = 1; j + (1<<(i-1)) <= n; j++) {
            spt[i][j] = min(spt[i-1][j], spt[i-1][j+(1<<(i-1))]);
        }
    }
}

ll query(ll l, ll r) {
    ll lg = (ll)(log2(r-l+1));
    return min(spt[lg][l], spt[lg][r-(1<<lg)+1]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        spt[0][i] = arr[i];
    }

    init();

    for (ll i = 0, v, l, r; i < q; i++) {
        cin >> v >> l >> r;

        // Modding by the first value from l to r <= v until v can't be modded anymore
        while (query(l, r) <= v) {
            ll lo = l, hi = r, mi = query(l, r);

            // Binary searching for the first value form l to r <= v
            while (lo <= hi) {
                ll mid = (lo+hi) / 2;

                if (query(l, mid) <= v) {
                    mi = query(l, mid);
                    hi = mid - 1;
                } else
                    lo = mid + 1;
            }

            v %= mi;
        }

        cout << v << '\n';
    }
}
