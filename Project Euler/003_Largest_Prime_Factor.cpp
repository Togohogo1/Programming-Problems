#include <bits/stdc++.h>

using namespace std;

long long ans, val = 600851475143;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    for (long long i = 2; i*i <= val; i++) {
        while (val % i == 0) {
            ans = max(ans, i);
            val /= i;
        }
    }

    cout << max(ans, val) << "\n";
}
