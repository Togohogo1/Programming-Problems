#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int M = 1502;
ll N, ans, nums[M];
unordered_map<ll, ll> frq, tmp[M];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            ll prod = nums[i]*nums[j];
            frq[prod]++;
            tmp[i][prod]++;
            tmp[j][prod]++;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            ll prod = nums[i]*nums[j], aux = tmp[i][prod] + tmp[j][prod] - 1;
            ans += (frq[prod]-aux)*4;
        }
    }

    cout << ans << '\n';
}
