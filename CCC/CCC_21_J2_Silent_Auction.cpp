#include <bits/stdc++.h>

using namespace std;

int N, val, mx;
string name, ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> name >> val;

        if (val > mx) {
            mx = val;
            ans = name;
        }
    }

    cout << ans << '\n';
}
