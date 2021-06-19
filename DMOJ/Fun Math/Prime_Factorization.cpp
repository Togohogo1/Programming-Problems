#include <bits/stdc++.h>

using namespace std;

int N, M;

void primeFact(int n) {
    while (n % 2 == 0) {
        cout << 2 << " ";
        n /= 2;
    }

    // Incriment must be odd, does not start at 2, because 2 already factored
    for (int i = 3; i*i <= n; i += 2) {
        // Loops through all values until it can't be divided
        while (n % i == 0) {
            cout << i << " ";
            n /= i;
        }
    }

    // The remaining number must be prime if its greater than 2
    if (n > 2)
        cout << n << "";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> M;

        primeFact(M);
        cout << "\n";
    }
}
