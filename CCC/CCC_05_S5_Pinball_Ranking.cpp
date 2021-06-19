#include <bits/stdc++.h>

using namespace std;

int t, s, bit[100002];
double ans;
vector<pair<int, int>> ranks;

int query(int idx) {
    int sum = 0;

    for (int i = idx; i > 0; i -= i&-i) {
        sum += bit[i];
    }

    return sum;
}

void update(int idx, int val) {
    for (int i = idx; i <= 100001; i += i&-i) {
        bit[i] += val;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;

    for (int i = 1; i <= t; i++) {
        cin >> s;
        ranks.push_back({s, i});
    }

    sort(ranks.begin(), ranks.end());

    for (int i = 0; i < t; i++) {
        // How many that came before it minus those that are smaller than it
        // Because sorted, no need to account for those larger than it
        ans += ranks[i].second - query(ranks[i].second-1);
        update(ranks[i].second, 1);
    }

    cout << fixed << setprecision(2) << ans/t << '\n';
}
