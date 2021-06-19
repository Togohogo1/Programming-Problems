#include <bits/stdc++.h>

using namespace std;

int J;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> J;
    cout << (J-1)*(J-2)*(J-3) / 6 << '\n';
}
