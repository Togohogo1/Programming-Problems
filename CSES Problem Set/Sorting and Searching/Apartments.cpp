#include <bits/stdc++.h>

using namespace std;

int n, m, k, ans;

int main() {
    cin >> n >> m >> k;
    int ppl[n];
    int ap[m];

    for (int i = 0; i < n; i++) {
        cin >> ppl[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> ap[i];
    }

    sort(ppl, ppl+n);
    sort(ap, ap+m);

    int ni = 0, mi = 0;

    while (ni < n && mi < m) {
        if (abs(ppl[ni] - ap[mi]) <= k) {
            ni++;
            mi++;
            ans++;
        } else if (ppl[ni] > ap[mi])
            mi++;
        else
            ni++;
    }

    cout << ans;
}
