#include <bits/stdc++.h>

using namespace std;

const int MN = 25000002;
int M, N, Q, q, diff[MN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> M >> N >> Q;

    for (int i = 1; i < M+1; i++) {
        for (int j = 1; j < N+1; j++) {
            int lb = i*j;
            int ub = i + j + (i-1)*N + (j-1)*M - lb;
            diff[lb]++;
            diff[ub+1]--;
        }
    }

    for (int i = 1; i < MN; i++) {
        diff[i] += diff[i-1];
    }

    while (Q--) {
        cin >> q;
        cout << diff[q] << '\n';
    }
}
