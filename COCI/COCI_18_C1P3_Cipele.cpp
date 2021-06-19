#include<bits/stdc++.h>

using namespace std;

const int MM = 1e5+2, MU = 1e9+2;
int N, M, lo, hi = MU, mid, ans, l[MM], r[MM];

bool check(int x) {
    int cnt = 0;

    for (int lp = 0, rp = 0; lp < N && rp < M;) {
        if (abs(l[lp]-r[rp]) <= x) {
            lp++;
            rp++;
            cnt++;
        } else if (l[lp] > r[rp])
            rp++;
        else if (l[lp] < r[rp])
            lp++;
    }

    return cnt == min(N, M);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> l[i];
    }

    for (int i = 0; i < M; i++) {
        cin >> r[i];
    }

    sort(l, l+N);
    sort(r, r+M);

    if (N > M) {
        swap(l, r);
        swap(N, M);
    }

    while (lo <= hi) {
        mid = (lo+hi) / 2;

        if (check(mid)) {
            ans = mid;
            hi = mid - 1;
        } else
            lo = mid + 1;
    }

    cout << ans << '\n';
}
