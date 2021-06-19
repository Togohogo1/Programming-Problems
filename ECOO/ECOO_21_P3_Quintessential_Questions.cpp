#include <bits/stdc++.h>

using namespace std;

const int MM = 2e5+2;
int N, M, K;
pair<int, int> arr[MM];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M >> K;

    for (int i = 1, A, B, C; i <= K; i++) {
        cin >> A >> B >> C;

        if (arr[B].first < C)
            arr[B] = {C, A};
    }

    for (int i = 1; i <= N; i++) {
        cout << (arr[i].second == 0 ? -1 : arr[i].second) << ' ';
    }

    cout << '\n';
}
