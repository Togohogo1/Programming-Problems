#include <bits/stdc++.h>

using namespace std;

int X, N, t;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> X >> N;
    int tot = (N+1)*X;

    while (N--) {
        cin >> t;
        tot -= t;
    }

    cout << tot << "\n";
}
