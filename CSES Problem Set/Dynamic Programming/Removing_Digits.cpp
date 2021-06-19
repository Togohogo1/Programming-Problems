#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

const int M = 1e6+2;
int n, tmp, dp[M];

vi dig(int n) {
    vi digs;

    while (n > 0) {
        digs.push_back(n % 10);
        n /= 10;
    }

    return digs;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        dp[i] = M;

        for (int j : dig(i)) {
            dp[i] = min(dp[i], dp[i-j]+1);
        }
    }

    cout << dp[n] << '\n';
}
