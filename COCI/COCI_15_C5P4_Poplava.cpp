#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int M = 1e6+2;
ll N, X, mx, dif, vis[M];
vector<int> bk;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> X;

    // Maximum water level
    mx = (N-2)*(N-1)/2;
    dif = mx - X;

    if (N < 3 || X > mx) {
        cout << -1 << '\n';
        return 0;
    }

    for (int i = N - 2; i > 0; i--) {
        if (i < dif) {
            dif -= i;
            vis[N-1-i] = true;
            bk.push_back(N-1-i);
        } else
            break;
    }

    for (int i = 1; i <= N - 2; i++) {
        if (dif - i == 0) {
            vis[N-1-i] = true;
            bk.push_back(N-1-i);
            break;
        }
    }

    cout << N << ' ';

    for (int i = 1; i < N; i++) {
        if (!vis[i])
            cout << i << ' ';
    }

    for (auto i = bk.rbegin(); i != bk.rend(); i++) {
        cout << *i << ' ';
    }

    cout << "\n";
}
