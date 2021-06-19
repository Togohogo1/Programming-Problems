#include <bits/stdc++.h>

using namespace std;

struct E {
    int t, pos;
};

bool cmp(E x, E y) {
    return x.t < y.t;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    E a[n];

    for(int i = 0, t, pos; i < n; i++) {
        cin >> t >> pos;
        a[i] = E{t, pos};
    }

    sort(a, a+n, cmp);
    double ans = 0.0;

    for(int i = 1; i < n; i++) {
        ans = max(ans, (double)abs(a[i].pos-a[i-1].pos)/(a[i].t-a[i-1].t));
    }

    cout << fixed << setprecision(9) << ans << endl;
}
