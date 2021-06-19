#include <bits/stdc++.h>

using namespace std;

long long N, t, s1, s2, m;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> t;
        s1 += t;
        m = max(m, t);
    }

    s2 = s1 - m;

    if (s2 <= m)
        cout << s2 << '\n';
    else
        cout << s1/2 << '\n';
}
