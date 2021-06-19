#include <bits/stdc++.h>

using namespace std;

int ans, t = 1, arr[20][20];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 16; j++) {
            t = 1;

            for (int k = 0; k < 4; k++) {
                t *= arr[i][j+k];
            }

            ans = max(ans, t);
        }
    }

    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 20; j++) {
            t = 1;

            for (int k = 0; k < 4; k++) {
                t *= arr[i+k][j];
            }

            ans = max(ans, t);
        }
    }

    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            t = 1;

            for (int k = 0; k < 4; k++) {
                t *= arr[i+k][j+k];
            }

            ans = max(ans, t);
        }
    }

    for (int i = 3; i < 20; i++) {
        for (int j = 3; j < 20; j++) {
            t = 1;

            for (int k = 0; k < 4; k++) {
                t *= arr[i-k][j+k];
            }

            ans = max(ans, t);
        }
    }

    cout << ans << '\n';
}
