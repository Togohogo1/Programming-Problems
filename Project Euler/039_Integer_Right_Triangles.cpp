#include <bits/stdc++.h>

using namespace std;

int t, ans, py[1001];

int isPy(int a, int b, int c) {
    return a*a + b*b == c*c;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    for (int i = 1; i <= 500; i++) {
        for (int j = 1; j <= 500; j++) {
            double k = sqrt(i*i + j*j);
            int K = k;

            if (K == k && i + j + K <= 1000) {
                py[i+j+K]++;
                t = max(t, py[i+j+K]);

                if (py[i+j+K] == t) {
                    ans = i+j+K;
                }
            }
        }
    }

    cout << ans << '\n';
}
