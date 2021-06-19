#include <bits/stdc++.h>

using namespace std;

int N, C, Q, ans, arr[1002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> C >> Q;

    for (int i = 0; i < N; i++) {
        arr[i] = C;
    }

    for (int i = 0, n; i < Q; i++) {
        cin >> n;

        for (int j = n - 1; j < N; j += n) {
            if (arr[j] - 1 >= 0)
                arr[j] -= 1;
            else
                arr[j] = 0;
        }
    }

    for (int i = 0; i < N; i++) {
        ans += arr[i];
    }

    cout << ans << '\n';
}
