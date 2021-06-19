#include <bits/stdc++.h>

using namespace std;

int t, m, n;
long long sum;

int main() {
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n >> m;
        sum = 0;

        for (int j = 0, a; j < n; j++) {
            cin >> a;
            sum += a;
        }

        cout << (sum == m ? "YES\n" : "NO\n");
    }
}
