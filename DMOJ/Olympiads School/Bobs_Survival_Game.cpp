#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MM = 2e5+2;
int N, T, M, cnt, arr[MM], diff[MM];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> T >> M;

    for (int i = 1; i <= N; i++) {
        arr[i] = T;
    }

    for (int i = 1, A; i <= M; i++) {
        cin >> A;
        diff[0] += 1;
        diff[A+1] += 1;
        diff[A] -= 1;
        diff[N+1] -= 1;
    }

    for (int i = 0; i <= N; i++) {
        diff[i] += diff[i-1];

        if (arr[i] - diff[i] > 0)
            cnt++;
    }

    cout << cnt << '\n';
}
