#include<bits/stdc++.h>

using namespace std;

const int M = 1e5+2;
int N, ans = M, arr[M];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        arr[i] += arr[i-1];
    }

    for (int i = 1; i <= N; i++) {
        ans = min(ans, abs((arr[i]-arr[0]) - (arr[N]-arr[i])));
    }

    cout << ans << '\n';
}
