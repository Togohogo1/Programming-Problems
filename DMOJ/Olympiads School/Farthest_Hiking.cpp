#include<bits/stdc++.h>

using namespace std;

const int MM = 1e5+2;
int M, N, U, F, D, ans, up[MM], down[MM];
string path;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> M >> N >> U >> F >> D >> path;

    for (int i = 1; i <= N; i++) {
        if (path[i-1] == 'u') {
            up[i] = up[i-1] + U;
            down[i] = down[i-1] + D;
        } else if (path[i-1] == 'd') {
            up[i] = up[i-1] + D;
            down[i] = down[i-1] + U;
        } else {
            down[i] = down[i-1] + F;
            up[i] = up[i-1] + F;
        }
    }

    for (int i = 1; i <= N; i++) {
        if (up[i] + down[i] <= M)
            ans = i;
    }

    cout << ans << '\n';
}
