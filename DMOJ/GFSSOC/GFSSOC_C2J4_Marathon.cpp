#include <bits/stdc++.h>

using namespace std;

const int MM = 5e5+2;
int N, Q, a, b, psa[MM];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> Q;

    for (int i = 0; i < N; i++) {
        cin >> psa[i+1];
        psa[i+1] += psa[i];
    }

    for (int i = 0; i < Q; i++) {
        cin >> a >> b;
        cout << (psa[N]-psa[b]) + (psa[a-1]-psa[0]) << '\n';
    }
}
