#include <bits/stdc++.h>

using namespace std;

long long m, ans;

long long hailstone(long long n) {
    long long c = 0;

    while (n > 1) {
        if (n % 2 == 0)
            n /= 2;
        else
            n = 3*n + 1;

        c++;
    }

    return c + 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    for (int i = 1; i <= 1000000; i++) {
        m = max(m, hailstone(i));

        if (hailstone(i) == m)
            ans = i;
    }

    cout << ans << '\n';
}
