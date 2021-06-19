#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int M = 2e5+2;
ll n, x, ans, arr[M];
map<ll, vector<int>> frq;

ll freq(int r, ll val) {
    return lower_bound(frq[val].begin(), frq[val].end(), r) - frq[val].begin();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> x;
    frq[0].push_back(0);

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] += arr[i-1];
        frq[arr[i]].push_back(i);
    }

    for (int i = 1; i <= n; i++) {
        if (!frq[arr[i]-x].empty())
            ans += freq(i, arr[i]-x);
    }

    cout << ans << '\n';
}
