#include <bits/stdc++.h>

using namespace std;

int I, N, J, ans, stations[100002];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> I >> N >> J;

    while (J--) {
        int lo, hi, cnt;
        cin >> lo >> hi >> cnt;

        // Applies range updating
        stations[lo-1] += cnt;
        stations[hi] -= cnt;
    }

    // Prefix sum array
    for (int i = 1; i <= I; i++) {
        stations[i] += stations[i-1];

        if (stations[i-1] < N)
            ans++;
    }

    cout << ans << '\n';
}
