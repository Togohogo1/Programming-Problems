#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e5;
int isPrime[MAX];
vector<int> primes;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    for (int i = 2; i < MAX; i++) {
        isPrime[i] = 1;
    }

    for (int i = 2; i < MAX; i++) {
        if (isPrime[i]) {
            primes.push_back(i);

            for (int j = i+i; j < MAX; j += i) {
                isPrime[j] = 0;
            }
        }
    }

    cout << primes[10000] << endl;
}
