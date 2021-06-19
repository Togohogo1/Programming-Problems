#include <bits/stdc++.h>

using namespace std;

const int M = 2e5, INF = 1e9;
int n, xi;
vector<int> lis;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    lis.push_back(INF);

    for (int i = 0; i < n; i++) {
        cin >> xi;

        int idx = lower_bound(lis.begin(), lis.end(), xi) - lis.begin();

        if (lis[idx] < xi)
            lis.push_back(xi);
        else
            lis[idx] = xi;
    }

    cout << lis.size() << '\n';
}
