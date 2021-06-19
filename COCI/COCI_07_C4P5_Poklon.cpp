#include <bits/stdc++.h>

using namespace std;

int N, m, pre[100002];
vector<pair<int, int>> segs, lis, ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    for (int i = 0, A, B; i < N; i++) {
        cin >> A >> B;
        segs.push_back({A, -B});  // (-) for LIS
    }

    sort(segs.begin(), segs.end());
    lis.push_back({-1e9, -1});

    for (int i = 0; i < N; i++) {
        // Use binary search to find position of insertion for LIS
        // Left values guaranteed to be in order, so only need to search right values
        int val = segs[i].second;
        int pos = upper_bound(lis.begin(), lis.end(), make_pair(val, i)) - lis.begin();

        if (lis.back().first <= val)
            lis.push_back({val, i});
        else
            lis[pos] = {val, i};

        // Pointer to the previous element (patience sort LIS finding)
        pre[i] = lis[pos-1].second;
    }

    // Number of segments
    cout << lis.size() - 1 << '\n';

    for (int i = lis.back().second; i != -1; i = pre[i]) {
        ans.push_back({segs[i].first, -segs[i].second});
    }

    reverse(ans.begin(), ans.end());

    for (auto i : ans) {
        cout << i.first << ' ' << i.second << endl;
    }
}
