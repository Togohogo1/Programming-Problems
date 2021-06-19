#include <bits/stdc++.h>

using namespace std;

int ans = 1, primes[10] = {2, 3, 5, 7, 11, 13, 17, 23, 29};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    // Totient maximum happens when primes are multiplied in sequential order.
    // This is because only relatively prime numbers of the totient maximum are prime themselves.
    for (int i : primes) {
        if (ans*i > 1000000)
            break;

        ans *= i;
    }

    cout << ans << "\n";
}
