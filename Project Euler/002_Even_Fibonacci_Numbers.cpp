#include <bits/stdc++.h>

using namespace std;

int ans, fib[50] = {1, 2};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    for (int i = 2; i < 50; i++) {
        fib[i] = fib[i-1] + fib[i-2];

        if (fib[i] % 2 == 0)
            ans += fib[i];

        if (fib[i] > 4e6)
            break;
    }

    cout << ans + 2 << "\n";
}
