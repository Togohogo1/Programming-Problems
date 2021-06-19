#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll t, x, y, n, tmp;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> x >> y >> n;
        tmp = (n-y) / x;
        cout << x*tmp + y << '\n';
    }
}
