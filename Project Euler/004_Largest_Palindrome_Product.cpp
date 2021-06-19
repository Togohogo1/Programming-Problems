#include <bits/stdc++.h>

using namespace std;

int ans;

int addPalin(int n) {
    int dig, num = n, rev = 0;

    while (num != 0) {
        dig = num % 10;
        rev = (rev*10) + dig;
        num /= 10;
    }

    return (rev == n ? n : 0);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    for (int i = 100; i <= 999; i++) {
        for (int j = 100; j <= 999; j++) {
            ans = max(ans, addPalin(i*j));
        }
    }

    cout << ans << "\n";
}
