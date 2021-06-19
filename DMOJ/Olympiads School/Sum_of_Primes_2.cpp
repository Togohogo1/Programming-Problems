#include <bits/stdc++.h>

using namespace std;

const int MV = 100007;
int Q, a, b, ppsa[MV];
bool cross[MV];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> Q;

    for (int i = 2; i < MV; i++) {
        if (!cross[i]) {
            ppsa[i] = i;

            for (int j = 2*i; j < MV; j += i) {
                cross[j] = true;
            }
        }
    }

    for (int i = 0; i < MV; i++) {
        ppsa[i] += ppsa[i-1];
    }

    for (int i = 0; i < Q; i++) {
        cin >> a >> b;
        cout << ppsa[b] - ppsa[a-1] << endl;
    }
}
