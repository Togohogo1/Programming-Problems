#include <bits/stdc++.h>

using namespace std;

const int M = 1e5+2;
int N, K, arr[M], dp[M];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= K; i++) {
        for (int j = 1; j <= N; j++) {
            if (i - arr[j] > 0 && !dp[i-arr[j]])
                dp[i] = 1;
        }
    }

    cout << (dp[K] ? "First" : "Second") << '\n';
}
