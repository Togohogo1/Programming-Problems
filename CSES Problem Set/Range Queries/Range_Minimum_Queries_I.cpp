#include <bits/stdc++.h>

using namespace std;

const int M = 2e5+2, LG = 18;
int n, q, spt[M][LG];

void init() {
    for (int j = 1; j <= LG; j++) {
        for (int i = 1; i + (1<<j) <= M; i++) {
            spt[i][j] = min(spt[i][j-1], spt[i+(1<<(j-1))][j-1]);
        }
    }
}

int query(int l, int r) {
    int lg = (int)log2(r-l+1);
    return min(spt[l][lg], spt[r-(1<<lg)+1][lg]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> spt[i][0];
    }

    init();

    for (int i = 0, a, b; i < q; i++) {
        cin >> a  >> b;
        cout << query(a, b) << '\n';
    }
}
