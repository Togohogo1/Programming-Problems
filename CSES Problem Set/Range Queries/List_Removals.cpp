#include<bits/stdc++.h>

using namespace std;

const int M = 2e5+2;
int n, arr[M], bit[M];

int query(int idx) {
    int sum = 0;

    for (int i = idx; i > 0; i -= i&-i) {
        sum += bit[i];
    }

    return sum;
}

void update(int idx, int val) {
    for (int i = idx; i < M; i += i&-i) {
        bit[i] += val;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        update(i, 1);
    }

    // arr is filled with 1s, mark arr[idx] as 0 when visited
    // Binary search through arr to find the lower bound where sum to idx = pi
    for (int i = 0, pi; i < n; i++) {
        int lo = 1, hi = n, ans = 0, mid = 0;
        cin >> pi;

        while (lo <= hi) {
            mid = (lo+hi) / 2;

            if (query(mid) < pi) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
                ans = mid;
            }
        }

        cout << arr[ans] << ' ';
        update(ans, -1);

    }

    cout << '\n';
}
