#include <algorithm>
#include <iostream>

using namespace std;

int N, M, a[100002];
long long ans = 0;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    sort(a, a+N);

    for(int i = 1; i < N; i++) {
        ans += upper_bound(a, a+i, M-a[i]) - a;
    }

    cout << ans << "\n";
}
