#include <bits/stdc++.h>

using namespace std;

int x, n;
multiset<int> lt, sp;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> x >> n;

    lt.insert(0);
    lt.insert(x);
    sp.insert(x);

    for (int i = 0, p; i < n; i++) {
        cin >> p;
        lt.insert(p);

        auto idx = lt.find(p);
        int l = *--idx, m = *++idx, r = *++idx;

        sp.erase(sp.find(r-l));
        sp.insert(m-l);
        sp.insert(r-m);

        cout << *--sp.end() << ' ';
    }

    cout << '\n';
}
