#include <bits/stdc++.h>

using namespace std;

int ans = 1, idx[7] = {1, 10, 100, 1000, 10000, 100000, 1000000};
string s;

int isPy(int a, int b, int c) {
    return a*a + b*b == c*c;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    for (int i = 0; i < 1000000; i++) {
        s += to_string(i);
    }

    for (int i : idx) {
        ans *= s[i]-'0';
    }

    cout << ans << '\n';
}
