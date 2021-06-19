#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll M = 3e9+2;
ll mi = M, ma;
vector<int> nums;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    for (ll i = 0, num; i < 7; i++) {
        cin >> num;
        mi = min(mi, num);
        ma = max(ma, num);
        nums.push_back(num);
    }

    auto it1 = find(nums.begin(), nums.end(), mi);
    nums.erase(it1);

    auto it2 =  find(nums.begin(), nums.end(), ma);
    nums.erase(it2);

    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i] + nums[j] == ma - mi) {
                cout << mi << ' ' << min(nums[i], nums[j]) << ' ' << max(nums[i], nums[j]) << '\n';
                return 0;
            }
        }
    }
}
