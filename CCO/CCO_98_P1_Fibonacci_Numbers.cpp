#include <bits/stdc++.h>

using namespace std;

int main() {
    int n = -1;
    vector<vector<int>> arr(201, vector<int>(50, 0));

    arr[1][49] = 1;
    arr[2][49] = 1;

    for (int i = 3; i < 201; i++) {
        for (int j = 49; j > 0; j--) {
            arr[i][j] += arr[i-1][j] + arr[i-2][j];

            if (arr[i][j] >= 10) {
                arr[i][j-1] += 1;
                arr[i][j] -= 10;
            }
        }
    }

    while (n != 0) {
        cin >> n;
        bool flag = false;

        for (int i = 0; i < 50; i++) {
            if (flag)
                cout << arr[n][i];
            else if (arr[n][i] != 0) {
                flag = true;
                cout << arr[n][i];
            }
        }

        cout << '\n';
    }
}
