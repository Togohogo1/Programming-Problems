#include <bits/stdc++.h>

using namespace std;

const int M = 1e6;
int n, arr[M+1];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;

    for (int i = 0, xi; i < n; i++) {
        cin >> xi;
        arr[xi]++;
    }

    for (int i = M; i; i--) {
        int cnt = 0;

        // Loop through all multiples of i
        for (int j = i; j <= M; j += i) {
            // arr[j] != 0 if it exists
            cnt += arr[j];
        }

        if (cnt > 1) {
            cout << i << '\n';
            return 0;
        }
    }
}
