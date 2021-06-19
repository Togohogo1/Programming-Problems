#include<bits/stdc++.h>

using namespace std;

const int MM = 2e5+2;
int N, rht[MM], pre[MM], suf[MM], ans[MM];
pair<int, int> lft[MM];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    for (int i = 0, A; i <= N; i++) {
        cin >> A;
        lft[i] = {A, i+1};
    }

    for (int i = 0; i < N; i++) {
        cin >> rht[i];
    }

    sort(lft, lft+N+1);
    sort(rht, rht+N);

    for (int i = 1; i <= N; i++) {
        suf[N-i] = max(suf[N-i+1], max((lft[N-i+1].first-rht[N-i]), 0));
        pre[i] = max(pre[i-1], max((lft[i-1].first-rht[i-1]), 0));
    }

    for (int i = 0; i <= N+1; i++) {
        ans[lft[i].second] = max(pre[i], suf[i]);
    }

    for (int i = 1; i <= N+1; i++) {
        cout << ans[i] << ' ';
    }

    cout << '\n';
}
