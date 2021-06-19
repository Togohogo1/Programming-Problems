#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll M = 5002;
ll n, sum, arr[M], dp[M][M];

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    for (int l = n; l > 0; l--) {
        for (int r = l; r <= n; r++) {
            if (l == r)
                dp[l][r] = arr[l];
            else
                dp[l][r] = max(arr[l]-dp[l+1][r], arr[r]-dp[l][r-1]);
        }
    }

    // Solving system of equations
    // X - Y = diff, X + Y = sum
    cout << (sum+dp[1][n])/2 << '\n';
}
