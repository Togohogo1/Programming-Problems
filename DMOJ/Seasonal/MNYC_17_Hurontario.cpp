#include <bits/stdc++.h>

using namespace std;

string A, B;
long long vsA, vsB, lA, lB, fin;
long long h[1000000];

int main () {
    h[0] = 1;

    cin >> A >> B;

    lA = A.length(),
    lB = B.length();

    for (int i = 1; i < min(lA, lB); i++) {
        h[i] = h[i-1] * 31;
    }

    for (int i = 0; i < min(lA, lB); i++) {
        vsA += h[i] * (A[A.size()-i-1] - 'A');
        vsB *= 31;
        vsB += B[i] - 'A';

        if (vsA == vsB) {
            fin = i + 1;
        }
    }

    cout << A << B.substr(fin) << endl;
    return 0;
}