#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int M = 2e5+2;
ll n, pre = 1, sum, arr[M];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr+n);

    for (int i = 0; i < n; i++) {
        if (pre >= arr[i])
            pre += arr[i];
    }

    cout << pre << '\n';
}
