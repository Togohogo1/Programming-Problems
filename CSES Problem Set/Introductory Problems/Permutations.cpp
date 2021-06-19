#include <bits/stdc++.h>

using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    if (N == 2 || N == 3)
        cout << "NO SOLUTION\n";
    else {
        for (int i = 0; i < N; i++) {
            int ans = (i % 2 == 0 ? ceil((N-i)/2.0) : N-i/2);
            cout << fixed << ans << ' ';
        }
    }
}
