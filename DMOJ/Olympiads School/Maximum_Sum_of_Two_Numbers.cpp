#include <bits/stdc++.h>

using namespace std;

int N, M, a, ans;
vector<int> nums;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> a;
        nums.push_back(a);
    }

    sort(nums.begin(), nums.end());

    for (int i : nums) {
        int lb = lower_bound(nums.begin(), nums.end(), M-i) - nums.begin() - (i + nums[lb] != M);

        if (i != nums[lb] && i + nums[lb] <= M)
            ans = max(ans, nums[lb]+i);
    }

    cout << ans << '\n';
}
