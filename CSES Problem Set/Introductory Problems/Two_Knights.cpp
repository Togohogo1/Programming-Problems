#include <bits/stdc++.h>

using namespace std;

long long  n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cout << fixed << setprecision(0) << (pow(i, 4)-pow(i, 2))/2 - 4*(i-2)*(i-1) << '\n';
    }
}
