#include <bits/stdc++.h>

using namespace std;

int N;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    if (N % 6 == 0 && N % 10 != 2)
        cout << "not a memer\n";
    else
        cout << "memer\n";
}
