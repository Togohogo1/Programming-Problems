#include <bits/stdc++.h>

using namespace std;

int N, sz, fil;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    sz = max(1, (int)ceil((-1+sqrt(1+8*N))*0.5));
    fil = (sz*(sz+1))/2 - N;

    vector<int> ans(sz, 1);

    for (int i = 0; fil > 0 && i < sz; i += 2) {
        fil--;
        ans[i] = 2;
    }

    for (int i = 1; fil > 0; i += 2) {
        fil--;
        ans[i] = 3;
    }

    cout << sz << '\n';

    for (int i : ans) {
        cout << i << ' ';
    }

    cout << '\n';
}
