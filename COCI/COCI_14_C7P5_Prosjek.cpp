#include <bits/stdc++.h>

using namespace std;

const int M = 300001;
int N, F, arr[M];

bool found(double lim) {
    double psa[M], m = 0;

    // Construct psa after subtracting lim from original array
    // Simplifies the problem: need to find out if average >= 0 exists
    for (int i = 1; i <= N; i++) {
        psa[i] = arr[i-1] + psa[i-1] - lim;
    }

    // Start the R at the minimum segment size
    for (int i = F; i <= N; i++) {
        // psa[a] - psa[b-1] >= 0
        if (psa[i] >= m)
            return true;

        // Start at i-F+1 because dist from R to L is F
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
    }

    double hi = 1e6, lo = 0;

    // Binary search value that may be possible average
    while (hi - lo > 0.001) {
        double mid = (hi+lo) / 2;

        if (found(mid))
            lo = mid;
        else
            hi = mid;
    }

    cout << fixed << setprecision(6) << lo << '\n';
}
