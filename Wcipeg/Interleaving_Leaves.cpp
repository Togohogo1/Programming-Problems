#include <bits/stdc++.h>

using namespace std;

int T, N;
string a, b, t;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> N >> a >> b;

        for (int i = N-1; i >= 0; i--) {
            t += b[i];
            t += a[i];
        }

        cout << t << '\n';
        t = "";
    }
}
