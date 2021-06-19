#include <bits/stdc++.h>

using namespace std;

long long K, N, X;
double m;

double solve(double a, double b, double c) {
    return (-b + sqrt(b*b-4*a*c)) / (2*a);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> K >> N;

    while (N--) {
        cin >> X;
        m = solve(1, 1, -2*K);

        if (X < m) {
            m = solve(2, 0, -(X*X-X+2*K));
            cout << (long long)(2*m + 1 - X) << '\n';
        } else
            cout << ceil(m) << '\n';
    }
}
