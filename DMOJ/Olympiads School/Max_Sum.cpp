#include <bits/stdc++.h>

using namespace std;

long long N, a, n_count, sum;
vector<long long> nums;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> a;
        nums.push_back(a);
        sum += abs(a);
    }

    for (int i = 0; i < N; i++) {
        if (nums[i] < 0) {
            n_count++;
            nums[i] *= -1;
        }
    }

    if (n_count % 2 == 0)
        cout << sum << "\n";
    else
        cout << sum - 2*(*min_element(nums.begin(), nums.end())) << "\n";
}
