#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

const int M = 2e5+2;
int n, q, tmp = 1, arr[M], ans[M], bit[M];
vector<pair<pair<int, int>, int>> qrys;
map<int, int> pre;

int query(int idx) {
    int ans = 0;

    for (int i = idx; i > 0; i -= i&-i) {
        ans += bit[i];
    }

    return ans;
}

void update(int idx, int val) {
    for (int i = idx; i < M; i += i&-i) {
        bit[i] += val;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        pre[arr[i]] = -1;
    }

    for (int i = 0, a, b; i < q; i++) {
        cin >> a >> b;
        qrys.push_back({{b, a}, i});
    }

    // Sorted by right bound {r, l}
    sort(qrys.begin(), qrys.end());

    for (auto i : qrys) {
        for (int j = tmp; j <= i.f.f; j++) {
            if (pre[arr[j]] == -1) {
                update(j, 1);
            } else {
                update(pre[arr[j]], -1);
                update(j, 1);
            }

            pre[arr[j]] = j;
        }

        tmp = i.f.f;
        ans[i.s] = query(i.f.f) - query(i.f.s-1);
    }

    for (int i = 0; i < q; i++) {
        cout << ans[i] << '\n';
    }
}
