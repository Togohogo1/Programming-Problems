#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll M = 1e5+2, INF = 1e18;
ll N, l = 1, r = 2, mx, mi, ans = INF, psa[M];

ll getMin(int l, int r) {
    mx = max(psa[l], max(psa[r]-psa[l], psa[N]-psa[r]));
    mi = min(psa[l], min(psa[r]-psa[l], psa[N]-psa[r]));
    return mx - mi;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> psa[i];
        psa[i] += psa[i-1];
    }

    while (l != N - 2 && r != N) {
        if (getMin(l, r+1) <= ans)
            ans = min(ans, getMin(l, ++r));
        else if (getMin(l+1, r) <= ans && l < r)
            ans = min(ans, getMin(++l, r));
        else
            r++;
    }

    cout << ans << '\n';
}
