#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    long T, X, c = 0;
    cin >> T;

    for (long i = 0; i < T; i++) {
        cin >> X;
        c = 0;

        while (X) {
            if (X % 2 == 0)
                X /= 2;
            else if (X != 3 && (X-3)%4 == 0 && (X-1)%2 == 0)
                X++;
            else
                X--;

            c++;
        }

        cout << c << endl;
    }
}
