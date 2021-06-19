#include <bits/stdc++.h>

using namespace std;

bool isPrime(int N) {
    if (N < 2)
        return false;

    for (int i = 2; i*i <= N; i++) {
        if (N % i == 0)
            return false;
    }

    return true;
}

int T, N;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> T;

    while (T--) {
        cin >> N;

        for (int i = 0; i < N; i++) {
            if (isPrime(i) && isPrime(2*N-i)) {
                cout << i << " " << 2*N-i << endl;
                break;
            }
        }
    }
}
