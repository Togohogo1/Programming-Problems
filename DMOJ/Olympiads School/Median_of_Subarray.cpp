#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int M = 1e5+2;
int N, L, ans, arr[M], bit[2*M];
ll L, ans;

ll query(int idx) {
    ll sum = 0;

    for (int i = idx+M; i > 0; i -= i&-i) {
        sum += bit[i];
    }

    return sum;
}

void update(int idx, int val) {
    for (int i = idx+M; i <= 2*M; i += i&-i) {
        bit[i] += val;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> L;

    for (int i = 1, A; i <= N ; i++) {
        cin >> A;

        // arr[i] = 1 if greater or equal to median, else -1
        arr[i] = A < L ? -1 : 1;
        arr[i] += arr[i-1];
    }

    update(0, 1);

    // psa[R] - psa[L-1] >= 0, psa[R]
    // psa[R] >= psa[L-1] when L-1 < L, counting inversions
    for (int i = 1; i <= N; i++) {
        ans += query(arr[i]);
        update(arr[i], 1);
    }

    cout << ans << '\n';
}
