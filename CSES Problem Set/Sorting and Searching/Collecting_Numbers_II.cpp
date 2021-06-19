#include<bits/stdc++.h>

using namespace std;

const int M = 2e5+2;
int n, m, cnt = 1, pre, arr[M], idx[M];

int cmp(int a, int b, int c, int d) {
    if (a < b && c > d)
        return 1;
    else if (a > b && c < d)
        return -1;
    else
        return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        idx[arr[i]] = i;
    }

    pre = idx[1];
    idx[n+1] = M;

    for (int i = 2; i <= n; i++) {
        if (idx[i] < pre)
            cnt++;

        pre = idx[i];
    }

    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;

        if (arr[a] < arr[b])
            swap(a, b);

        int ha = idx[arr[a]-1], hb = idx[arr[b]-1];
        int ia = idx[arr[a]], ib = idx[arr[b]];
        int ja = idx[arr[a]+1], jb = idx[arr[b]+1];

        if (abs(arr[a]-arr[b]) == 1)
            cnt += cmp(hb, ib, hb, ia) + cmp(ib, ia, ia, ib) + cmp(ia, ja, ib, ja);
        else
            cnt += cmp(hb, ib, hb, ia) + cmp(ib, jb, ia, jb) + cmp(ha, ia, ha, ib) + cmp(ia, ja, ib, ja);

        swap(arr[a], arr[b]);
        swap(idx[arr[a]], idx[arr[b]]);

        cout << cnt << '\n';
    }
}
