#include <bits/stdc++.h>

using namespace std;

int B, tmp;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> B;
    tmp = 5*B - 400;

    if (tmp < 100)
        cout << tmp << '\n' << 1 << '\n';
    else if (tmp > 100)
        cout << tmp << '\n' << -1 << '\n';
    else
        cout << 100 << '\n' << 0 << '\n';
}
