#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6+2;
long long N, ans, pillar[MAX], maxL[MAX], maxR[MAX];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> pillar[i];
    }

    for (int i = 1; i <= N; i++) {
        maxL[i] = max(maxL[i-1], pillar[i]);
        maxR[N-i+1] = max(maxR[N-i+2], pillar[N-i+1]);
    }

    for (int i = 0; i <= N; i++) {
        ans += min(maxL[i], maxR[i]) - pillar[i];
    }

    cout << ans << '\n';
}
