#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, M, f, a, d;
    int tot = 0;
    int flowers[100001];

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> f;
        tot += f;
        flowers[i] = f;
    }

    cin >> M;

    for (int i = 0; i < M; i++) {
        cin >> a >> d;
        tot -= min({flowers[a], flowers[a-1], d});
    }

    cout << tot << "\n";
}
