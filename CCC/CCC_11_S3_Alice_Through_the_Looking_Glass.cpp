#include <bits/stdc++.h>

using namespace std;

int T, m, x, y, grid[5][5];

bool mag(int m, int x, int y) {
    if (m == 1)
        return grid[x][y] == 1;

    int sz = (int)pow(5, m-1), bx = x/sz, by = y/sz;

    if (grid[bx][by] == 1)
        return true;
    else if (grid[bx][by] == 0)
        return false;
    else
        return mag(m-1, x%sz, y%sz);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    grid[1][0] = grid[2][0] = grid[3][0] = grid[2][1] = 1;  // Crystal
    grid[1][1] = grid[2][2] = grid[3][1] = -1;  // Not sure

    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> m >> x >> y;
        cout << (mag(m, x, y) ? "crystal\n" : "empty\n");
    }
}
