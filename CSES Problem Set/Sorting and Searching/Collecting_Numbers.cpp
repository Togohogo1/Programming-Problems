#include<bits/stdc++.h>

using namespace std;

const int M = 2e5+2;
int n, pre, cnt = 1, idx[M];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;

    for (int i = 1, xi; i <= n; i++) {
        cin >> xi;
        idx[xi] = i;
    }

    pre = idx[1];

    for (int i = 2; i <= n; i++) {
        if (idx[i] < pre)
            cnt++;

        pre = idx[i];
    }

    cout << cnt << '\n';
}
