#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int R, C, Q, xi, yi;
bool xq[1001], yq[1001];
string curr;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        cin >> curr;

        for (int j = 0; j < C; j++) {
            if (curr[j] == 'X') {
                xq[j+1] = true;
                yq[i+1] = true;
            }
        }
    }

    cin >> Q;

    for (int i = 0; i < Q; i++) {
        cin >> xi >> yi;

        if (xq[xi] || yq[yi])
            cout << "Y\n";
        else
            cout << "N\n";
    }
}
