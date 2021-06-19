#include <bits/stdc++.h>

using namespace std;

int N, g;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;
    int arr[N];

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    // Given numbers: a, b, c, d => a%m = b&m = c%m = d%m
    // Rolling GCD of: a%m = b%m => (a-b)%m
    for (int i = 0; i < N-1; i++) {
        g = __gcd(g, abs(arr[i+1] - arr[i]));
    }

    for (int i = 2; i*i <= g; i++) {
        if (g % i == 0) {
            cout << i << " ";

            // No repeating values
            if (i*i != g)
                cout << g/i << " ";
        }
    }

    cout << g << "\n";
}
