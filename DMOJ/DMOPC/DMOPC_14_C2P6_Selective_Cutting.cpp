#include <bits/stdc++.h>

using namespace std;

int N, Q;
long long bit[100002];
vector<int> loc[20002];
map<int, vector<tuple<int, int, int>>> cut;
map<int, int> ans;

long long query(int idx) {
    long long sum = 0;

    for (int i = idx; i > 0; i -= i&-i) {
        sum += bit[i];
    }

    return sum;
}

void update(int idx, int val) {
    for (int i = idx; i <= 100002; i += i&-i) {
        bit[i] += val;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        int mi;
        cin >> mi;

        if (cut[mi].size() == 0)
            cut[mi].push_back({-1, -1, -1});

        loc[mi].push_back(i);
    }

    cin >> Q;

    for (int i = 1; i <= Q; i++) {
        int a, b, q;
        cin >> a >> b >> q;

        cut[q].push_back({a, b, i});

        if (get<2>(cut[q][0]) == -1)
            cut[q].erase(cut[q].begin());
    }

    for (auto i = cut.rbegin(); i != cut.rend(); i++) {
        int sz = i->first;

        for (auto k : loc[sz]) {
            update(k, sz);
        }

        if (get<2>((i->second)[0]) != -1) {
            for (auto j: i->second) {
                int l = get<0>(j), r = get<1>(j), ind = get<2>(j);
                ans[ind] = query(r+1) - query(l);
            }
        }
    }

    for (auto i : ans) {
        cout << i.second << '\n';
    }
}
