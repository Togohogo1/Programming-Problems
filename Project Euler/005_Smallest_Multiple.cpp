#include <bits/stdc++.h>

using namespace std;

int ans = 1;

int lcm(int a, int b) {
    return a*b / __gcd(a, b);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    for (int i = 2; i < 20; i++) {
        ans = lcm(ans, i);
    }

    cout << ans << '\n';
}
