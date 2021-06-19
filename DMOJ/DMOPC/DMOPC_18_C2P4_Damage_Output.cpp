#include <bits/stdc++.h>

using namespace std;

long long N, M, psa[500002];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> psa[i+1];
        psa[i+1] += psa[i];
    }

    int l = 0, r = 0, len = 500002;

    while (r <= N) {
        if (psa[r] - psa[l] < M)
            r++;
        else
            l++;

        if (psa[r] - psa[l] >= M)
            len = min(len, r-l);
    }

    cout << (len > N ? -1 : len) << '\n';
}
