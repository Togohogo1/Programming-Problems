#include<bits/stdc++.h>

using namespace std;

const int M = 1.5e5+2;
int N, vi, psa[M], bit[2*M];
long long ans = 0;

void update(int idx, int val) {
    // Adding M to idx in case of negative position
    for (int i = idx+M; i <= 2*M; i += i&-i) {
        bit[i] += val;
    }
}

long long query(int idx) {
    long long sum = 0;

    for (int i = idx+M; i > 0; i -= i&-i) {
        sum += bit[i];
    }

    return sum;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> vi;

        // Candidate 1 -> 1, Candidate 2 -> -1
        psa[i] = psa[i-1] + (vi == 1 ? 1 : -1);
    }

    update(0, 1);

    for (int i = 1; i <= N; i++) {
        // Count how many subarrays are positive
        // Inversion: psa[R] - psa[L-1] > 0 => psa[L-1] < psa[R]
        // for each index: how many to the left are less than it
        ans += query(psa[i] - 1);
        update(psa[i], 1);
    }

    cout << ans << '\n';
}
