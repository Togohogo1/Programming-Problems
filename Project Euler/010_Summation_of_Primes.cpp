#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e6;
long long ans, prime[MAX];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    for (int i = 2; i < MAX; i++) {
        prime[i] = 1;
    }

    for (long long i = 2; i*i < MAX; i++) {
        if (prime[i]) {
            for (long long j = i*i; j < MAX; j += i) {
                prime[j] = 0;
            }
        }
    }

    for (int i = 0; i < MAX; i++) {
        if (prime[i]) {
            ans += i;
        }
    }

    cout << ans << '\n';
}
