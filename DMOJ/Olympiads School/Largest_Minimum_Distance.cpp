#include<bits/stdc++.h>

using namespace std;

const int MM = 1e5+2;
int N, M, pi, lo, hi = 1e9+2, mid, ans, seats[MM];

bool check(int x) {
    int cnt = 1, pre = 0;

    for (int i = 1; i < N; i++) {
        if (seats[i] - seats[pre] >= x) {
            pre = i;
            cnt++;
        }
    }

    return cnt >= M;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> seats[i];
    }

    sort(seats, seats+N);

    while (lo <= hi) {
        mid = (lo+hi) / 2;

        if (check(mid)) {
            ans = mid;
            lo = mid + 1;
        } else
            hi = mid - 1;
    }

    cout << ans << '\n';
}
