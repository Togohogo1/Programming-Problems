#include <bits/stdc++.h>

using namespace std;

const int M = 2e5+2;
int n, lp, rp, ans, arr[M];
map<int, int> mp;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        mp[arr[i]] = 0;
    }

    while (rp < n) {
        if (mp[arr[rp]] < 1) {
            mp[arr[rp]] += 1;
            rp++;
        } else {
            while (mp[arr[rp]] >= 1 && lp < rp) {
                mp[arr[lp]]--;
                lp++;
            }
        }

        ans = max(ans, rp-lp);
    }

    cout << ans << '\n';
}
