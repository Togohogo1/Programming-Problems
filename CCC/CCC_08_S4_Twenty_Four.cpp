#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int N, ans, card[4];

void check(int val) {
    if (val <= 24)
        ans = max(ans, val);
}

void fun(int cur, int nxt, int idx) {
    if (idx == 3) {
        check(cur+nxt);
        check(cur-nxt);
        check(cur*nxt);
        if (nxt != 0 && cur % nxt == 0)
            check(cur/nxt);

        return;
    }

    fun(cur+nxt, card[idx+1], idx+1);
    fun(cur-nxt, card[idx+1], idx+1);
    fun(cur*nxt, card[idx+1], idx+1);
    if (nxt != 0 && cur % nxt == 0)
        fun(cur/nxt, card[idx+1], idx+1);

    fun(cur, nxt+card[idx+1], idx+1);
    fun(cur, nxt-card[idx+1], idx+1);
    fun(cur, nxt*card[idx+1], idx+1);
    if (card[idx+1] != 0 && nxt % card[idx+1] == 0)
        fun(cur, nxt/card[idx+1], idx+1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        ans = 0;

        for (int j = 0; j < 4; j++) {
            cin >> card[j];
        }

        sort(card, card+4);

        do  {
            fun(card[0], card[1], 1);
        } while (next_permutation(card, card+4));

        cout << ans << '\n';
    }
}
