#include <bits/stdc++.h>

using namespace std;

#define b begin
#define e end
#define all(x) x.b(), x.e()
#define ub upper_bound

typedef long long ll;

ll l, r, sz, A, B, N, dp[7002];
vector<ll> arr = {0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> A >> B >> N;

    for (ll i = 0, m; i < N; i++) {
        cin >> m;
        arr.push_back(m);
    }

    sort(arr.begin(), arr.end());
    sz = arr.size();
    dp[0] = 1;

    // dp[i] = number of ways to get to stop at distance i
    for (int i = 0; i < sz; i++) {
        l = ub(all(arr), arr[i]-B) - arr.b();
        r = ub(all(arr), arr[i]-A) - arr.b();

        if (l != 0 && arr[i] - B == arr[l-1])
            l--;

        for (int j = l; j < r; j++) {
            dp[i] += dp[j];
        }
    }

    cout << dp[sz-1] << '\n';
}
