#include <bits/stdc++.h>

using namespace std;

int N, ans = 1;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    while (ceil(ans*ans*0.5) < N) {
        ans++;
    }

    cout << ans-1 << '\n';
}
