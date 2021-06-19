#include <bits/stdc++.h>

using namespace std;

int I, N, table[1030][1030];
int X, Y, A, L, B, R, T;

int query(int r, int c) {
    int sum = 0;

    for (int i = r + 1; i > 0; i -= i&-i) {
        for (int j = c + 1; j > 0; j -= j&-j) {
            sum += table[i][j];
        }
    }

    return max(sum, 0);
}

void update(int r, int c, int val) {
    for (int i = r + 1; i <= 1030; i += i&-i) {
        for (int j = c + 1; j <= 1030; j += j&-j) {
            table[i][j] += val;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    while (true) {
        cin >> I;

        if (I == 0)
            cin >> N;

        else if (I == 1) {
            cin >> X >> Y >> A;
            update(X, Y, A);

        } else if (I == 2) {
            cin >> L >> B >> R >> T;
            cout << query(R, T) - query(R, B-1) - query(L-1, T) + query(L-1, B-1) << '\n';

        } else if (I == 3)
            break;
    }
}
