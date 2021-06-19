#include<bits/stdc++.h>

using namespace std;

const int M = 2e5+2;
int n, m;
map<int, int> mp;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;

    for (int i = 0, h; i < n; i++) {
        cin >> h;
        mp[h]++;
    }

    for (int i = 0, t; i < m; i++) {
        cin >> t;
        auto it = mp.upper_bound(t);

        if (it == mp.begin())
            cout << -1 << '\n';
        else {
            it--;
            it->second--;

            cout << it->first << '\n';

            if (it->second == 0)
                mp.erase(it);
        }
    }
}
