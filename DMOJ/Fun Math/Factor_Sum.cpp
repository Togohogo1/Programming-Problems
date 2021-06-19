#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll M = 1e12;
bool flag = false;
ll N, F, tmp, pre, cnt = 1;

ll factorSum(ll n) {
    ll ans = 0;

    for (ll i = 1; i*i <= n; i++) {
        if (n % i == 0 && i*i != n) {
            ans += i;
            ans += n/i;
        } else if (i*i == n)
            ans += i;
    }

    return (ans-n >= M ? -1 : ans-n);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    for (int i = 0, num; i < N; i++) {
        cin >> num;

        flag = false;
        cnt = 0;
        tmp = factorSum(num);

        if (tmp <= 1)
            cout << num << ' ' << 0 << '\n';
        else {
            while (tmp != 1) {
                cnt++;
                pre = tmp;
                tmp = factorSum(tmp);

                if (cnt >= 1000) {
                    cout << "INFINITY\n";
                    flag = true;
                    break;
                }

                if (tmp == -1) {
                    cout << "INFINITY\n";
                    flag = true;
                    break;
                }
            }

            if (!flag)
                cout << pre << ' ' << cnt << '\n';
        }
    }
}
