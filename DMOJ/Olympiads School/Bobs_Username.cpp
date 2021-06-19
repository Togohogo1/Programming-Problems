#include <bits/stdc++.h>

using namespace std;

long long K, N;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> K >> N;
    cout << fixed << (long long)pow(N, K) << '\n';
}
