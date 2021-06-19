#include <bits/stdc++.h>

using namespace std;

int N, tot, mh;
int canvas[202][8002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    for (int i = 0, hi; i < N; i++) {
        cin >> hi;

        for (int j = tot; j < tot + hi; j++) {
            canvas[200][2*j] = i+1;
        }

        tot += hi;
        mh = max(mh, hi);
    }

    for (int i = 199; i >= 0; i--) {
        for (int j = 1; j < 8001; j++) {
            if (canvas[i+1][j-1] == canvas[i+1][j+1] && canvas[i+1][j-1])
                canvas[i][j] = canvas[i+1][j-1];
        }
    }

    for (int i = 201-mh; i <= 200; i++) {
        for (int j = 0; j < 2*tot; j++) {
            cout << (!canvas[i][j] ? " ": "^");
        }

        cout << '\n';
    }
}
