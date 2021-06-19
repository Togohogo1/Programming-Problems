#include <bits/stdc++.h>

using namespace std;

long arr[22][22];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    arr[1][1] = 1;

    for (int i = 1; i < 22; i++) {
        for (int j = 1; j < 22; j++) {
            if (i != 1 || j != 1)
                arr[i][j] = arr[i-1][j] + arr[i][j-1];
        }
    }

    cout << arr[21][21] << endl;
}
