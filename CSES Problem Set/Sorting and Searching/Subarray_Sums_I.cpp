#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int M = 2e5+2;
ll n, x, l, r, sum, ans, arr[M];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> x;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    while (l < n) {
        if (sum < x && r < n)
            sum += arr[r++];
        else {
            ans += (sum == x);
            sum -= arr[l++];
        }
    }

    cout << ans << '\n';
}
