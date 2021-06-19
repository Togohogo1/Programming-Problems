#include <bits/stdc++.h>

using namespace std;

const int M = 202;
int N, sum, arr[M], dp[M];

int main() {
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    for (int l = N; l > 0; l--) {
        for (int r = l; r <= N; r++) {
            if (r == l)
                dp[r] = arr[r];
            else
                dp[r] = max(arr[l]-dp[r], arr[r]-dp[r-1]);
        }
    }

    cout << (dp[N]+sum)/2 << ' ' << (sum-dp[N])/2 << '\n';
}
