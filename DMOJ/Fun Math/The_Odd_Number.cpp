#include<bits/stdc++.h>

using namespace std;

int N, x, ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> x;
        ans ^= x;
    }

    cout << ans << '\n';
}
