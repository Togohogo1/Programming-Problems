#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll K, cnt, sqrtK;
vector<ll> nums;

void fetch(ll x) {
    cnt++;

    for (ll i = 0; i < x; i++) {
        nums.push_back(cnt);

        if (nums.size() > 1e5) {
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> K;

    K++;
    sqrtK = sqrt(K) + 1;

    for (ll i = 2; i <= sqrtK; i++) {
        while (K % i == 0) {
            fetch(i-1);
            K /= i;
        }
    }

    if (K > 2)
        fetch(K-1);

    if (nums.size() > 1e5) {
        cout << "Sad Chris\n";
    } else {
        cout << nums.size() << '\n';

        for (ll i : nums) {
            cout << i << ' ';
        }

        cout << '\n';
    }
}
