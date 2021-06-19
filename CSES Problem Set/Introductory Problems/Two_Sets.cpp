#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int M = 1e6+2;
ll n, sum, arr[M];
vector<ll> set1, set2;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        sum += i;
        arr[i] = i;
    }

    if (sum & 1)
        cout << "NO\n";
    else {
        cout << "YES\n";
        sum /= 2;

        for (int i = n; i > 0; i--) {
            if (i <= sum) {
                sum -= i;
                set1.push_back(i);
            } else
                set2.push_back(i);
        }

        cout << set1.size() << '\n';

        for (int i : set1) {
            cout << i << ' ';
        }

        cout << '\n' << set2.size() << '\n';

        for (int i : set2) {
            cout << i << ' ';
        }

        cout << '\n';
    }
}
