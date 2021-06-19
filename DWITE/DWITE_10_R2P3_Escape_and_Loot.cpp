#include <bits/stdc++.h>

using namespace std;

int best;
char grid[9][8];

void find(int r, int c, int m) {
    if (r < 0 || c > 7 || grid[r][c] == '#')
        return;

    if (grid[r][c] != '.' && grid[r][c] != '#')
        m += grid[r][c] - '0';

    if (r == 0 && c == 7)
        best = max(best, m);
    else {
        find(r-1, c, m);
        find(r, c+1, m);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    for (int i = 0; i < 5; i++) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 8; j++) {
                cin >> grid[i][j];
            }
        }

        best = 0;
        find(7, 0, 0);
        cout << best << "\n";
    }
}
