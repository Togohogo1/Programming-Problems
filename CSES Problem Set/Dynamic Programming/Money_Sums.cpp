#include <bits/stdc++.h>

using namespace std;

const int M = 2e5+2;
int n, arr[102], dp[M];
set<int> ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = M; j >= 0; j--) {
            if (j - arr[i] >= 0)
                dp[j] |= dp[j-arr[i]];

            if (dp[j] && j)
                ans.insert(j);
        }
    }

    cout << ans.size() << '\n';

    for (auto i : ans) {
        cout << i << ' ';
    }

    cout << '\n';
}
