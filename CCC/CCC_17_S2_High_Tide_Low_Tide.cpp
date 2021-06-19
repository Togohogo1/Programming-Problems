#include <bits/stdc++.h>
#include <cmath>
#include <iostream>

using namespace std;

int N, idx, t;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    int tides[N];

    for (int i = 0; i < N; i++) {
        cin >> tides[i];
    }

    sort(tides, tides+N);

    for (int i = 0; i < N; i++) {
        t = i / 2;

        if (i & 1)
            cout << tides[idx+t] << " ";
        else {
            idx = ceil(N/2.0);
            cout << tides[idx-t-1] << " ";
        }
    }

    cout << "\n";
}
