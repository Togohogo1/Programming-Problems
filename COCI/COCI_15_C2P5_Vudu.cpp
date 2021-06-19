#include<bits/stdc++.h>

using namespace std;

const int M = 1e6+2;
int N, P, idx, bit[M];
long long ans, psa[M], aux[M];

int query(int idx) {
    int sum = 0;

    for (int i = idx; i > 0; i -= i&-i) {
        sum += bit[i];
    }

    return sum;
}

void update(int idx, int val) {
    for (int i = idx; i <= M; i += i&-i) {
        bit[i] += val;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> psa[i];
    }

    cin >> P;

    // Apply some maths, must subtract P from each value
    // Then add as psa, get the identity psa[L-1] <= psa[R] = counting inversions
    for (int i = 1; i <= N; i++) {
        psa[i] = psa[i] + psa[i-1] - P;
        aux[i] = psa[i];
    }

    sort(aux, aux+N+1);

    // Starts at 0 because value at psa[0] might be smaller than an psa[i], i > 0
    for (int i = 0, idx; i <= N; i++) {
        // lower_bound for coordinate compression, +1 to avoid while loop
        idx = lower_bound(aux, aux+N+1, psa[i]) - aux + 1;
        ans += query(idx);
        update(idx, 1);
    }

    cout << ans << '\n';
}
