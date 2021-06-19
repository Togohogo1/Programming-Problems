#include<bits/stdc++.h>

using namespace std;

long N, t, sum;

int main() {
    cin >> N;

    while (cin >> t) {
        sum += t;
    }

    cout << N*(N+1)/2 - sum << "\n";
}
