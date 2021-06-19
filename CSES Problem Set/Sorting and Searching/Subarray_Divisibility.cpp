#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int M = 2e5+2;
ll n, ans, psa[M], mod[M];
map<ll, vector<int>> mp;

ll freq(int r, ll val) {
    return lower_bound(mp[val].begin(), mp[val].end(), r) - mp[val].begin();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    mp[0].push_back(0);

    // psa[R] = n1*k + r1, psa[L-1] = n2*k + r2
    // psa[R] - psa[L-1] = (n1-n2)*k + r1-r2
    // psa[R] % k = psa[L-1] % k
    // psa[R] = r1, psa[L-1] = r2, psa[R] - psa[L-1] = 0
    // For each index R, count appearances of psa[L-1] before it
    for (int i = 1; i <= n; i++) {
        cin >> psa[i];
        psa[i] += psa[i-1];
    }

    for (int i = 1; i <= n; i++) {
        psa[i] = (psa[i] % n + n) % n;
        mp[psa[i]].push_back(i);
    }

    for (int i = 1; i <= n; i++) {
        ans += freq(i, psa[i]);
    }

    cout << ans << '\n';
}
