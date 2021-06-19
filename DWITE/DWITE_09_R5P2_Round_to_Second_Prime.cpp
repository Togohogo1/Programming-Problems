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

int np(int N) {
    N++;

    while (!isPrime(N)) {
        N++;
    }

    return N;
}

int pp(int N) {
    N--;

    while (!isPrime(N)) {
        N--;
    }

    return N;
}

int N, nnp, ppp;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    for (int i = 0; i < 5; i++) {
        cin >> N;

        nnp = np(np(N));
        ppp = pp(pp(N));

        cout << (abs(N - nnp) > abs(N - ppp) ? ppp : nnp) << "\n";
    }
}
