#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9+7;
int N, op, r, c, x;
long long bit[2002][2002], ans; // Not 2D BIT, but 2D array of BITs

long long query(long long bit[], int pos) {
    long long sum = 0;

    for (int i = pos; i > 0; i -= i&-i) {
        sum = (sum + bit[i]) % MOD;
    }

    return sum;
}

void update(long long bit[], int pos, int val) {
    for (int i = pos; i <= 2002; i += i&-i) {
        bit[i] += val;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> op >> r >> c >> x;

        // Treat each diagonal line as BIT
        if (op == 1)
            update(bit[r+c], r, x);
        else
            ans += query(bit[r+c], r) - query(bit[r+c], r-x-1);
    }

    cout << ans % MOD << '\n';
}
