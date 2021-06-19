#include <bits/stdc++.h>

using namespace std;

const int M = 10002;
double ans, N, H[M], L[M];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    for (int i = 0; i <= N; i++) {
        cin >> H[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> L[i];
    }

    for (int i = 0; i < N; i++) {
        ans += ((H[i]+H[i+1])*(L[i])) / 2;
    }

    cout << fixed << setprecision(1) << ans << '\n';
}
