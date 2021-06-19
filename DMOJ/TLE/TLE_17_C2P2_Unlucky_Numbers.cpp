#include <bits/stdc++.h>

using namespace std;

int K, N, f;
int ul[500002];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> K;

    for (int i = 0; i < K; i++) {
        cin >> ul[i];
    }

    sort(ul, ul+K);
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> f;
        cout << f - (lower_bound(ul, ul+K, f) - ul) << endl;
    }
}
