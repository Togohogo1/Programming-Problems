#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int M = 2e5+2;
ll N, ans, arr[M];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    for (int i = 0; i < N - 1; i++) {
        cin >> arr[i];
    }

    ans = arr[0] + arr[N-2];

    for (int i = 0; i < N - 2; i++) {
        ans += min(arr[i], arr[i+1]);
    }

    cout << ans << '\n';
}
