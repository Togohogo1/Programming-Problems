#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll N, K, prod, ans, tmp;
bool of;
vector<ll> pr;

void comb(int n, int r) {
    vector<bool> v(n);
    fill(v.begin(), v.begin()+r, true);

    do {
        prod = 1, tmp = 0;
        of = false;

        for (int i = 0; i < n; i++) {
            if (v[i]) {
                tmp = prod;
                prod *= pr[i];

                if (tmp != prod/pr[i]) {
                    of = true;
                    break;
                }
            }
        }

        if (!of)
            ans = ans + (r & 1 ? N/prod : -N/prod);

    } while (prev_permutation(v.begin(), v.end()));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> K;

    for (ll i = 0, ai; i < K; i++) {
        cin >> ai;
        pr.push_back(ai);
        ans += N/ai;
    }

    for (int i = 2; i <= K; i++) {
        comb(K, i);
    }

    cout << ans << '\n';
}
