#include <bits/stdc++.h>

using namespace std;

long long N, psa[200002], ans[100002];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> psa[i];
        psa[i] += psa[i-1];
    }

    for (int i = 1; i <= N/2+1; i++) {
        ans[i] = psa[N-i+1] - psa[i-1];
        ans[i] += ans[i-1];
    }

    for (int i = 1; i <= N; i++) {
        cout << (i < N/2+1 ? ans[i] : ans[N-i+1]) << '\n';
    }
}
