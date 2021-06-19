#include <bits/stdc++.h>

using namespace std;

int n, ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;

    for (int i = 0, tmp; i <= n; i += 5) {
        tmp = i;

        if (tmp >= 5) {
            while (tmp % 5 == 0) {
                tmp /= 5;
                ans++;
            }
        }
    }

    cout << ans << '\n';
}
