#include <bits/stdc++.h>

using namespace std;

const int M = 100001;
int N, F, arr[M];

bool found(int lim) {
    long psa[M], m = 0;

    for (int i = 1; i <= N; i++) {
        psa[i] = arr[i-1] + psa[i-1] - lim;
    }

    for (int i = F; i <= N; i++) {
        if (psa[i] >= m)
            return true;

        m = min(m, psa[i-F+1]);
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> F;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        arr[i] *= 1000;
    }

    int hi = 2000000, lo = 0;

    while (hi >= lo) {
        int mid = (hi+lo) / 2;

        if (found(mid))
            lo = mid + 1;
        else
            hi = mid - 1;
    }

    cout << lo - 1 << '\n';
}
