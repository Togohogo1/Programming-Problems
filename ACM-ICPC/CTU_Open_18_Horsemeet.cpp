#include <bits/stdc++.h>

using namespace std;

int w1, w2, b1, b2;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> w1 >> w2 >> b1 >> b2;

    // Combinations: (01, 10) = False or (00, 11) = True
    bool W = (w1%2 == w2%2), B = (b1%2 == b2%2);

    cout << (W == B ? "black" : "white") << "\n";
}
