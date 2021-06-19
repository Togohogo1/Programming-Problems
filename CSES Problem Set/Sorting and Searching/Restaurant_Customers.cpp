#include <bits/stdc++.h>

using namespace std;

const int M = 2e5+2;
int n, a, b, cur, tmp = 1, ans = 1;
map<int, int> mp;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        mp[a]++;
        mp[b+1]--;
    }

    for (auto i : mp) {
        cur += i.second;
        ans = max(ans, cur);
    }

    cout << ans << '\n';
}
