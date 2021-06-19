#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, arr[22];
ll ans = 1e9*20, tot;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        tot += arr[i];
    }

    // n = 2 (0000 0001 0010 0011)
    for (int i = 0; i < 1 << n; i++) {
        ll sum = 0;

        for (int j = 0; j < n; j++) {
            // if bit at position j is 1
            if (i & (1 << j))
                sum += arr[j];
        }

        ans = min(ans, abs(tot-2*sum));
    }

    cout << ans << '\n';
}
