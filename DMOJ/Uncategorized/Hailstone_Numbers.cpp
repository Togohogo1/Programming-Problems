#include <bits/stdc++.h>

using namespace std;

int n, cnt;

int main() {
    cin >> n;

    while (n != 1)
        if (n % 2 == 1) {
            n = (n * 3) + 1;
            cnt += 1;
        }

        else if (n % 2 == 0) {
            n /= 2;
            cnt += 1;
        }

    cout << cnt << '\n';
}
