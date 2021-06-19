#include <bits/stdc++.h>

using namespace std;

int n, x;

int countFact(int n) {
    int tmp, ans = 1;

    for (int i = 2; i*i <= n; i++) {
        while (n % i == 0) {
            n /= i;
            tmp++;
        }

        ans *= tmp+1;
        tmp = 0;
    }

    if (n > 1)
        ans *= 2;

    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        cout << countFact(x) << '\n';
    }
}
