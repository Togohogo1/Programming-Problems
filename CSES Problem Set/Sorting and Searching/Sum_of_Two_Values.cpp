#include <bits/stdc++.h>

using namespace std;

int n, x;
map<int, int> mp;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> x;

    for (int i = 1, a; i <= n; i++) {
        cin >> a;

        if (mp.count(x-a)) {
            cout << mp[x-a] << ' ' << i << '\n';
            return 0;
        }

        mp[a] = i;
    }

    cout << "IMPOSSIBLE\n";
}
