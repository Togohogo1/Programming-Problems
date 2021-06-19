#include<bits/stdc++.h>

using namespace std;

const int M = 2e5+2;
int n, x, cnt, r, l, arr[M];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> x;
    l = n - 1;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr+n);

    while (r <= l) {
        if (arr[r] + arr[l] <= x) {
            r++;
            l--;
        } else {
            l--;
        }

        cnt++;
    }

    cout << cnt << '\n';
}
