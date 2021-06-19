#include <bits/stdc++.h>

using namespace std;

int N, vil[102];
double ans = 2e9 + 1;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> vil[i];
    }

    sort(vil, vil+N);

    for (int i = 1; i < N-1; i++) {
        double l = (vil[i]-vil[i-1]) / 2.0;
        double r = (vil[i+1]-vil[i]) / 2.0;
        ans = min(ans, l+r);
    }

    cout << fixed << setprecision(1) << ans << "\n";
}
