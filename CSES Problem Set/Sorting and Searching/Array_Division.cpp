#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int M = 2e5+2;
ll n, k, lo = 1, hi, ans, arr[M];

bool check(ll val) {
    ll tmp = 0, cnt = 1;

    for (int i = 0; i < n; i++) {
        if (tmp + arr[i] <= val)
            tmp += arr[i];
        else if (arr[i] > val)
            return false;
        else {
            tmp = arr[i];
            cnt++;
        }
    }

    return cnt <= k;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        hi += arr[i];
    }

    while (lo <= hi) {
        ll mid = (lo+hi) / 2;

        if (check(mid)) {
            ans = mid;
            hi = mid - 1;
        } else
            lo = mid + 1;
    }

    cout << ans << '\n';
}
