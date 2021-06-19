#include<bits/stdc++.h>

using namespace std;

const int M = 1e6;
int N, ai, arr[M];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr+N);

    if (N % 2 == 1) {
        cout << 0 << '\n';
    } else {
        int idx = N/2;
        cout << arr[idx] - arr[idx-1] << '\n';
    }
}
