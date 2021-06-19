#include <bits/stdc++.h>

using namespace std;

int A, B, C;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> A >> B >> C;
    int j1 = B-A-1, j2 = C-B-1;

    cout << max(j1, j2) << "\n";
}
