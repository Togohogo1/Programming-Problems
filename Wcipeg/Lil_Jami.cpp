#include<bits/stdc++.h>

using namespace std;

const int M = 10;
int N, K, ki, a, b, Q;
long long psa[M];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> K;

    for (int i = 0; i < K; i++) {
        cin >> ki;
        psa[ki+1]++;
    }

    for (int i = 1; i <= N; i++) {
        psa[i] += psa[i-1];
    }

    cin >> Q;

    for (int i = 0; i < Q; i++) {
        cin >> a >> b;
        cout << psa[b+1] - psa[a] << '\n';
    }
}
