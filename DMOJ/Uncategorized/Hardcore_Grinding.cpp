#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e7+2;
int N, s, f, ans, diff[MAX];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    while (N--) {
        cin >> s >> f;
        diff[s]++;
        diff[f]--;
    }

    for (int i = 1; i < MAX; i++) {
        diff[i] += diff[i-1];
        ans = max(ans, diff[i]);
    }

    cout << ans << '\n';
}
