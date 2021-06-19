#include<bits/stdc++.h>

using namespace std;

const int M = 2e5+2;
int n;
multiset<int> towers;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;

    for (int i = 0, xi; i < n; i++) {
        cin >> xi;
        auto it = towers.upper_bound(xi);

        if (it != towers.end()) {
            towers.erase(it);
        }

        towers.insert(xi);
    }

    cout << towers.size() << '\n';
}
