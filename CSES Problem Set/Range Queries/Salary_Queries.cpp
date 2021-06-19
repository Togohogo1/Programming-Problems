#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

const int M = 2e5+2;
int n, q, idx, arr[M], bit[3*M];
char op;
vector<int> nums;
vector<pair<char, pair<int, int>>> qrys;
map<int, int> cc;

int query(int idx) {
    int ans = 0;

    for (int i = idx; i > 0; i -= i&-i) {
        ans += bit[i];
    }

    return ans;
}

void update(int idx, int val) {
    for (int i = idx; i < 3*M; i += i&-i) {
        bit[i] += val;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        nums.push_back(arr[i]);
    }

    for (int i = 0, a, b; i < q; i++) {
        cin >> op >> a >> b;
        qrys.push_back({op, {a, b}});

        nums.push_back(b);

        if (op == '?')
            nums.push_back(a);
    }

    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());

    for (auto i : nums) {
        cc[i] = ++idx;
    }

    for (int i = 1; i <= n; i++) {
        update(cc[arr[i]], 1);
    }

    for (auto i : qrys) {
        if (i.f == '!') {
            update(cc[arr[i.s.f]], -1);
            arr[i.s.f] = i.s.s;
            update(cc[i.s.s], 1);
        } else
            cout << query(cc[i.s.s]) - query(cc[i.s.f]-1) << '\n';
    }
}
