#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct fr {
    ll pos, spd, rng;
};

const int M = 2e5+2;
ll N, hi = 1e18, lo = 0;
vector<fr> vec;

ll dist(ll n) {
    ll ans = 0;

    for (fr i : vec) {
        if (i.pos + i.rng < n)
            ans += (n-(i.pos+i.rng))*i.spd;
        else if (i.pos - i.rng > n)
            ans += ((i.pos-i.rng)-n)*i.spd;
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    for (ll i = 0, P, W, D; i < N; i++) {
        cin >> P >> W >> D;
        vec.push_back({P, W, D});
    }

    while (lo < hi) {
        ll mid = (lo+hi) / 2;

        if (dist(mid) < dist(mid+1))
            hi = mid;
        else
            lo = mid + 1;
    }

    cout << dist(hi) << '\n';
}
