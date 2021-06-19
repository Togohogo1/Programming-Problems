#include <bits/stdc++.h>

using namespace std;

const int M = 1e5+2, A = 26;
int N, Q, pre[A][M], suf[A][M], visp[A], viss[A];
string s;

int query(int l, int r) {
    int ans = 0;

    for (int i = 0; i < A; i++) {
        ans += pre[i][l-1] + suf[i][r+1];
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> Q >> s;

    // Prefix
    for (int i = 0; i < A; i++) {
        bool flag = false;

        for (int j = 1; j <= N; j++) {
            pre[i][j] = pre[i][j-1];

            if (s[j-1] - 'A' == i && !flag) {
                flag = true;
                pre[i][j]++;
            }

            if (s[j-1] - 'A' < i)
                flag = false;
        }
    }

    // Suffix
    for (int i = 0; i < A; i++) {
        bool flag = false;

        for (int j = N; j > 0; j--) {
            suf[i][j] = suf[i][j+1];

            if (s[j-1] - 'A' == i && !flag) {
                flag = true;
                suf[i][j]++;
            }

            if (s[j-1] - 'A' < i)
                flag = false;
        }
    }

    for (int i = 0, a, b; i < Q; i++) {
        cin >> a >> b;
        cout << query(a, b) << '\n';
    }
}
