#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool o(int n) {
    return n & 1;
}

bool e(int n) {
    return !o(n);
}

int f(int n) {
    return o(n) ? 1 : -1;
}

int g(int n) {
    return e(n) ? 1 : -1;
}

ll t, y, x;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> y >> x;

        if (y >= x)
            cout << (y-o(y))*(y-o(y)) + o(y) + (x-1)*f(y) << '\n';
        else
            cout << (x-e(x))*(x-e(x)) + e(x) + (y-1)*g(x) << '\n';
    }
}
