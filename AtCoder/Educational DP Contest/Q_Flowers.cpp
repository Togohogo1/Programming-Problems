#include <bits/stdc++.h>

using namespace std;

const int M = 2e5+2;
int N, hi, fl[M], bt[M];
long long mv, mbit[M];

long long query(int idx) {
    long long ans = 0;

    for (int i = idx; i > 0; i -= i&-i) {
        ans = max(ans, mbit[i]);
    }

    return ans;
}

void update(int idx, long long val) {
    for (int i = idx; i <= M; i += i&-i) {
        mbit[i] = max(mbit[i], val);
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> fl[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> bt[i];
    }

    for (int i = 0; i < N; i++) {
        mv = max(query(fl[i]), query(fl[i])+bt[i]);
        update(fl[i], mv);
    }

    cout << query(M) << '\n';
}
