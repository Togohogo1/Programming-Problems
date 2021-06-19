#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll N, K;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> K;
    cout << min(abs(N%K), abs(N%K-K)) << '\n';
}
