#include <bits/stdc++.h>

using namespace std;

long long N, ans, arr[200002];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];

        if (arr[i] < arr[i-1]) {
            ans += arr[i-1] - arr[i];
            arr[i] = arr[i-1];
        }
    }

    cout << ans << '\n';
}
