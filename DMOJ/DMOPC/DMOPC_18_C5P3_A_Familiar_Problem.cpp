#include <bits/stdc++.h>

using namespace std;

long long N, M, psa[200002];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> psa[i];
        psa[i] += psa[i-1];
    }

    int l = 0, r = 1, len = -1;

    while (r <= N) {
        if (psa[r] - psa[l] < M)
            r++;
        else
            l++;

        len = max(len, r-l);
    }

    cout << len - 1 << '\n';
}
