#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int M = 2e5+2;
ll n, k, ans, pre, arr[M];
multiset<ll> ms;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < k; i++) {
        ms.insert(arr[i]);
    }

    auto it = ms.begin();
    advance(it, (k+1)/2-1);

    for (int i = 0; i < k; i++) {
        ans += abs(arr[i]-*it);
    }

    pre = *it;
    cout << ans << ' ';

    for (int i = k; i < n; i++) {
        ms.insert(arr[i]);

        if (arr[i] >= *it) {
            if (arr[i-k] <= *it)
                it++;
        } else {
            if (arr[i-k] >= *it)
                it--;

            if (arr[i-k] == *it)
                it++;
        }

        ans += abs(*it-arr[i]) - abs(pre-arr[i-k]);

        if (k % 2 == 0)
            ans -= *it - pre;

        pre = *it;
        cout << ans << ' ';

        ms.erase(ms.find(arr[i-k]));
    }

    cout << '\n';
}
