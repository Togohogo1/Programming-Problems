#include<bits/stdc++.h>

using namespace std;

long long x, y, A, B, hi, lo, lcm, a, b, c;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> x >> y >> A >> B;

    hi = y;
    lo = x-1;
    lcm = (A*B)/__gcd(A, B);

    a = hi/A - lo/A;
    b = hi/B - lo/B;
    c = hi/(lcm) - lo/(lcm);

    cout << a + b - c << '\n';
}
