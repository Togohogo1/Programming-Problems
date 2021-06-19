#include <bits/stdc++.h>

using namespace std;

const int M = 1e9+2;
int N, ans;
queue<int> q;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;
    q.push(-1);

    for (int i = 0, ai; i < N; i++) {
        cin >> ai;

        if (ai <= q.back())
            q.push(ai);
        else {
            q = {};
            q.push(ai);
        }

        ans = max(ans, (int)q.size());
    }

    cout << ans << '\n';
}
