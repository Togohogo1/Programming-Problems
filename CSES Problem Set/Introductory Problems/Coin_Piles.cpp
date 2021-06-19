#include <bits/stdc++.h>

using namespace std;

const int M = 1e5+2;
int t, a, b;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> a >> b;

        if (a > b)
            swap(a, b);

        cout << ((a+b) % 3 == 0 && b <= 2*a ? "YES" : "NO") << '\n';
    }
}
