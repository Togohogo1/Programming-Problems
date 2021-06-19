#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MM = 1e5+2;
int N, M, lo, hi, arr[MM];
ll mid, ans;

bool check(ll x) {
    int count = 1;
    ll sum = 0;

    for (int i = 1; i <= N; i++) {
        if (sum + arr[i] <= x)
            sum += arr[i];
        else {
            count++;
            sum = arr[i];
        }
    }

    return count <= M;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        lo = max(lo, arr[i]);
        hi += arr[i];
    }

    while (lo <= hi) {
        mid = (lo+hi) / 2;

        if (check(mid)) {
            ans = mid;
            hi = mid - 1;
        } else
            lo = mid + 1;
    }

    cout << ans << '\n';
}
