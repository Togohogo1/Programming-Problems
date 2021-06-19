#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int N, sw, se, t;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    int swift[N], semap[N];

    for (int i = 0; i < N; i++) {
        cin >> swift[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> semap[i];
    }

    for (int i = 0; i < N; i++) {
        sw += swift[i];
        se += semap[i];

        if (sw == se) {
            t = i + 1;
        }
    }

    cout << t << "\n";
}
