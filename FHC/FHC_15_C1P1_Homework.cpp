#include <bits/stdc++.h>

using namespace std;

const int M = 1e7+2;
int N, freq[M];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    for (int i = 2; i < M; i++) {
        if (freq[i] == 0)
            for (int j = i; j < M; j += i)
                freq[j]++;
    }

    cin >> N;

    for (int i = 0; i < N; i++) {
        int lo, hi, pri, ans = 0;
        cin >> lo >> hi >> pri;

        for (int j = lo; j <= hi; j++) {
            if (freq[j] == pri)
                ans++;
        }

        cout << "Case #" << i+1 << ": " << ans << "\n";
    }
}
