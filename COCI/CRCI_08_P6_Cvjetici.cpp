#include<bits/stdc++.h>

using namespace std;

const int M = 1e5+2;
int N, L, R, aux[M], bit[M];

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

void rupdate(int l, int r, int val) {
    update(l, val);
    update(r+1, -val);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> L >> R;

        if (R - L > 1)
            rupdate(L+1, R-1, 1);

        aux[R] += query(R);
        aux[L] += query(L);

        cout << aux[R] + aux[L] << "\n";

        aux[R] = -query(R);
        aux[L] = -query(L);
    }
}
